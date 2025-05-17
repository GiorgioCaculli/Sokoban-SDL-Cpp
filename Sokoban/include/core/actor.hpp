#ifndef ACTOR_HPP
#define ACTOR_HPP

#include <string>

class Actor
{
public:
    /** Default constructor
     * \param x The X coordinate on the board
     * \param y The Y coordinate on the board
     */
    Actor( int x, int y );

    /** Default destructor */
    virtual ~Actor();

    /** Copy constructor
     *  \param other Object to copy from
     */
    Actor( const Actor &other );

    /** Assignment operator
     *  \param other Object to assign from
     *  \return A reference to this
     */
    Actor &operator=( const Actor &other );

    /** Check for a collision on the left
     * \param actor The actor to collide with
     */
    bool is_left_collision( const Actor *actor ) const;

    /** Check for a collision on the right
     * \param actor The actor to collide with
     */
    bool is_right_collision( const Actor *actor ) const;

    /** Check for a collision on the top
     * \param actor The actor to collide with
     */
    bool is_top_collision( const Actor *actor ) const;

    /** Check for a collision on the bottom
     * \param actor The actor to collide with
     */
    bool is_bottom_collision( const Actor *actor ) const;

    /** Access x
     * \return The current value of x
     */
    int get_x() const;

    /** Set x
     * \param x New value to set
     */
    void set_x( int x );

    /** Access y
     * \return The current value of y
     */
    int get_y() const;

    /** Set y
     * \param y New value to set
     */
    void set_y( int y );

    /** String information concerning the actor
     * \return String containing the actor's information
     */
    virtual std::string to_string() const;
private:
    int _x; //!< Member variable "_x"
    int _y; //!< Member variable "_y"
};

#endif // ACTOR_HPP
