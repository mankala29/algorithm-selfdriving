# Autonomous Vehicle Routing


Ride-hailing companies like Uber and Lyft have become ubiquitous means to get around cities. Efficient vehicle routing,
or figuring out the fastest and most efficient way to direct vehicles to pick up and drop off multiple passengers at a
time, has become a crucial component of their success.

In the near future you are the proud owner of an autonomous vehicle! You want to let some friends use it whenever they
want so you make an app to let them call the vehicle to come pick them up. In this problem you will develop a system to
keep track of the state of your car and your friends.

Here are some more constraints to help you code your solution:
The city is a grid of perpendicular blocks. At initialization your code should take as inputs the number of streets in
both the x and y directions (ex. x=10, y=10).

The car can move in any direction exactly 1 block at a time. For our purposes, we only care about when the car is at a
vertex of two intersecting streets, so continuing our example, a car can be at the intersection (0, 0) in the upper-left
corner of our city, or (9, 9) in the bottom-right corner.

There should be a function to advance time by one time-step (and hence the vehicle by one block in any direction). This
function should accept a list of ride requests from your friends. These ride requests come in the form of a list of JSON
elements like so:

{ requests: [
    {
      'name': 'Elon',
      'start': (3,5),
      'end': (8,7)
    },
    {
      'name': 'George',
      'start': (1,2),
      'end': (4,3)
    }
  ]
}

At each time step this list of requests can be an empty list (ex. []), or infinitely long. At each time step you should
print out the current position of the vehicle and the names of all of the passengers currently in the vehicle, as well
as anybody being dropped off or being picked up at this intersection. (We will assume your car can fit infinitely many
people at a time.)

Your goal is to schedule your car to get people where they want to go as fast as possible. Of course, you will likely
have to make some trade-offs in the process.
