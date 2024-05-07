/**
 * @file
 * @brief Contains the declaration of the RandomConvexShape class.
 * @author Tobias Mayer
 * @date 07.05.2024
*/

#ifndef RANDOMCONVEXSHAPE_HPP
#define RANDOMCONVEXSHAPE_HPP

#include <SFML/Graphics.hpp>

class RandomConvexShape : public sf::ConvexShape {
private:
    void sortPoints(std::vector<sf::Vector2f>& pointsToSort);
    float angleBetweenTwoPoints(const sf::Vector2f& PointOne, const sf::Vector2f& PointTwo) const;

protected:

public:
    /**
     * @brief Constructor.
     * @author Tobias Mayer
     * @date 07.05.2024
     * @param[in] position The position of the shape.
     * @param[in] boundingBoxSize The size of the boundingBox in which the random points will be generated.
     * @param[in] numberOfPoints The count of Points that are to be generated for this shape.
     * 
     * The constructor generates a random shape, based upon the given arguments. Due to restrictions from the SFML library
     * the points have to be sorted in a way that they are either clock or counterclockwise ordered, otherwise it may not draw the shape correctly.
    */
    RandomConvexShape(sf::Vector2f position, sf::Vector2i boundingBoxSize, int countOfPoints);

};

#endif