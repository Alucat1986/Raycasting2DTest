/**
 * @file
 * @brief Contains the implementation of the RandomConvexShape class.
 * @author Tobias Mayer
 * @date 07.05.2024
*/

#include <chrono>
#include <cmath>
#include <numbers>
#include <iostream>
#include <random>

#include "../include/randomConvexShape.hpp"

int quadrantOfPoint(const sf::Vector2f& point, const sf::Vector2f& origin);

// ****************************************************************************************************************** //
//                                                                                                                    //
//                                                      CLASSES                                                       //
//                                                                                                                    //
// ****************************************************************************************************************** //

// ****************************************************************************************************************** //
//                                                                                                                    //
//                                                      PRIVATE                                                       //
//                                                                                                                    //
// ****************************************************************************************************************** //

/**
 * @brief Sorts the given vector of point to get them into a clockwise order.
 * @author Tobias Mayer
 * @date 07.05.2024
 * @param[in,out] pointsToSort The vector of points that needs sorting.
*/
void RandomConvexShape::sortPoints(std::vector<sf::Vector2f>& pointsToSort) {
    sf::Vector2f originPoint = this->getOrigin();
    std::vector<float> anglesToPoints;

    for ( unsigned char i = 0; i < pointsToSort.size(); i++ ) {
        anglesToPoints.push_back(angleBetweenTwoPoints(originPoint, pointsToSort.at(i)));
        std::cout << "P1(" << originPoint.x << "/" << originPoint.y << ") to ";
        std::cout << "P2(" << pointsToSort.at(i).x << "/" << pointsToSort.at(i).y << ") ";
        std::cout << "Q" << quadrantOfPoint(pointsToSort.at(i), originPoint) << ": ";
        std::cout << "Angle " << i << ": " << anglesToPoints.at(i) << "\370\n";
    } // for ( unsigned char i = 0; i < pointsToSort.size(); i++ )

    sf::Vector2f tempPoint;
    float tempAngle;
    char previous;

    for ( unsigned char current = 1; current < pointsToSort.size(); current++ ) {
        tempAngle = anglesToPoints.at(current);
        tempPoint = pointsToSort.at(current);
        previous = current - 1;
        while ( previous >= 0 && anglesToPoints.at(previous) > tempAngle ) {
            anglesToPoints[previous+1] = anglesToPoints[previous];
            pointsToSort[previous+1] = pointsToSort[previous];
            previous--;
        } // while ( previous >= 0 && anglesToPoints.at(previous) > tempAngle )
        anglesToPoints[previous+1] = tempAngle;
        pointsToSort[previous+1] = tempPoint;
    } // for ( unsigned char i = 1; i < pointsToSort.size(); i++ )

    return;
}

/**
 * @brief Calculates the angle between two given points.
 * @author Tobias Mayer
 * @date 07.05.2024
 * @param[in] pointOne First point.
 * @param[in] pointTwo Second point.
 * @return The angle in degrees
*/
float RandomConvexShape::angleBetweenTwoPoints(const sf::Vector2f& PointOne, const sf::Vector2f& PointTwo) const {
    return (std::atan2(PointOne.y - PointTwo.y, PointOne.x - PointTwo.x) * 180 / std::numbers::pi)+180;
}

int quadrantOfPoint(const sf::Vector2f& point, const sf::Vector2f& origin) {
    if ( point.x > origin.x && point.y > origin.y ) return 1;
    else if ( point.x < origin.x && point.y > origin.y ) return 2;
    else if ( point.x < origin.x && point.y < origin.y ) return 3;
    return 4;
}
// ****************************************************************************************************************** //
//                                                                                                                    //
//                                                     PROTECTED                                                      //
//                                                                                                                    //
// ****************************************************************************************************************** //

// ****************************************************************************************************************** //
//                                                                                                                    //
//                                                      PUBLIC                                                        //
//                                                                                                                    //
// ****************************************************************************************************************** //

RandomConvexShape::RandomConvexShape(sf::Vector2f position, sf::Vector2i boundingBoxSize, int countOfPoints) {
    std::random_device random;
    std::mt19937::result_type seed = random() ^ ( 
        (std::mt19937::result_type) std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch()).count() +
        (std::mt19937::result_type) std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch()).count() );
    std::mt19937 randomGenerator(seed);

    std::vector<sf::Vector2f> points;
    this->setOrigin(boundingBoxSize.x / 2.f, boundingBoxSize.y / 2.f);
    this->setPosition(position);
    this->setPointCount(countOfPoints);

    for ( unsigned char i = 0; i < countOfPoints; i++ ) {
        sf::Vector2f randomPoint;

        randomPoint.x = static_cast<float>(randomGenerator() % boundingBoxSize.x);
        randomPoint.y = static_cast<float>(randomGenerator() % boundingBoxSize.y);
        points.push_back(randomPoint);
        std::cout << "Random Point(" << randomPoint.x << "/" << randomPoint.y << ")\n";
    } // for ( unsigned char i = 0; i < countOfPoints; i++ )

    this->sortPoints(points);

    for ( unsigned char i = 0; i < countOfPoints; i++ ) {
        this->setPoint(i, points.at(i));
    } // for ( unsigned char i = 0; i < countOfPoints; i++ )

    this->setFillColor(sf::Color::Cyan);
    this->setOutlineColor(sf::Color::Red);
    this->setOutlineThickness(2);
    return;
}