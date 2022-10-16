#include <boost/python.hpp>
#include "HRVO.h"
#include "Vector2.h"
#include "Goal.h"
#include "Simulator.h"

namespace hvro {
 
    BOOST_PYTHON_MODULE(pyhrvo)
    {
        using namespace boost::python;
        // def("say_hello", say_hello);
        class_<hrvo::Vector2>("Vector2",  init<float, float>())
        	.def("getX", &hrvo::Vector2::getX)
        	.def("getY", &hrvo::Vector2::getY)
        	.def("setX", &hrvo::Vector2::setX)
        	.def("setY", &hrvo::Vector2::setY)
        ;
        
        // via http://www.boost.org/doc/libs/1_55_0/libs/python/doc/tutorial/doc/html/python/functions.html
        // unsigned long (hrvo::Simulator::*addAgent0)(hrvo::Vector2 &, unsigned long) = &hrvo::Simulator::addAgent;
        // bool (hrvo::*addAgent1)(hrvo::Vector2, std::size_t, float, std::size_t, float, float, float, float, float, float, float, float, hrvo::Vector2, float)      = &hrvo::addAgent;
        // TODO not working. In the meantime, remove overloading by renaming.

        //via http://stackoverflow.com/questions/10142417/boostpython-compilation-fails-because-copy-constructor-is-private
        class_<hrvo::Simulator, boost::noncopyable>("Simulator", init<>())
            .def("addAgent0", &hrvo::Simulator::addAgent0)
            .def("addAgent1", &hrvo::Simulator::addAgent1)
            .def("addGoal", &hrvo::Simulator::addGoal)
            .def("doStep", &hrvo::Simulator::doStep)
            .def("getAgentGoal", &hrvo::Simulator::getAgentGoal)
            .def("getAgentGoalRadius", &hrvo::Simulator::getAgentGoalRadius)
            // .def("getAgentLeftWheelSpeed", &hrvo::Simulator::getAgentLeftWheelSpeed)
            .def("getAgentMaxAccel", &hrvo::Simulator::getAgentMaxAccel)
            .def("getAgentMaxNeighbors", &hrvo::Simulator::getAgentMaxNeighbors)
            .def("getAgentMaxSpeed", &hrvo::Simulator::getAgentMaxSpeed)
            .def("getAgentNeighborDist", &hrvo::Simulator::getAgentNeighborDist)
            .def("getAgentOrientation", &hrvo::Simulator::getAgentOrientation)
            .def("getAgentPosition", &hrvo::Simulator::getAgentPosition)
            .def("getAgentPrefSpeed", &hrvo::Simulator::getAgentPrefSpeed)
            .def("getAgentRadius", &hrvo::Simulator::getAgentRadius)
            .def("getAgentReachedGoal", &hrvo::Simulator::getAgentReachedGoal)
            // .def("getAgentRightWheelSpeed", &hrvo::Simulator::getAgentRightWheelSpeed)
            // .def("getAgentTimeToOrientation", &hrvo::Simulator::getAgentTimeToOrientation)
            .def("getAgentUncertaintyOffset", &hrvo::Simulator::getAgentUncertaintyOffset)
            .def("getAgentVelocity", &hrvo::Simulator::getAgentVelocity)
            // .def("getAgentWheelTrack", &hrvo::Simulator::getAgentWheelTrack)
            .def("getGlobalTime", &hrvo::Simulator::getGlobalTime)
            .def("getGoalPosition", &hrvo::Simulator::getGoalPosition)
            .def("getNumAgents", &hrvo::Simulator::getNumAgents)
            .def("getNumGoals", &hrvo::Simulator::getNumGoals)
            .def("getTimeStep", &hrvo::Simulator::getTimeStep)
            .def("haveReachedGoals", &hrvo::Simulator::haveReachedGoals)
            .def("setAgentDefaults", &hrvo::Simulator::setAgentDefaults)
            .def("setAgentGoal", &hrvo::Simulator::setAgentGoal)
            .def("setAgentGoalRadius", &hrvo::Simulator::setAgentGoalRadius)
            .def("setAgentMaxAccel", &hrvo::Simulator::setAgentMaxAccel)
            .def("setAgentMaxNeighbors", &hrvo::Simulator::setAgentMaxNeighbors)
            .def("setAgentMaxSpeed", &hrvo::Simulator::setAgentMaxSpeed)
            .def("setAgentNeighborDist", &hrvo::Simulator::setAgentNeighborDist)
            .def("setAgentOrientation", &hrvo::Simulator::setAgentOrientation)
            .def("setAgentPosition", &hrvo::Simulator::setAgentPosition)
            .def("setAgentPrefSpeed", &hrvo::Simulator::setAgentPrefSpeed)
            .def("setAgentRadius", &hrvo::Simulator::setAgentRadius)
            // .def("setAgentTimeToOrientation", &hrvo::Simulator::setAgentTimeToOrientation)
            // .def("setAgentWheelTrack", &hrvo::Simulator::setAgentWheelTrack)
            .def("setAgentUncertaintyOffset", &hrvo::Simulator::setAgentUncertaintyOffset)
            .def("setAgentVelocity", &hrvo::Simulator::setAgentVelocity)
            .def("setTimeStep", &hrvo::Simulator::setTimeStep)
        ;
    }

}