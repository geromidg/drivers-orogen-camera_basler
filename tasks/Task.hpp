#ifndef CAMERA_BASLER_TASK_HPP
#define CAMERA_BASLER_TASK_HPP

#include "camera_basler/TaskBase.hpp"

// TODO: Rename project to camera_basler_gige to avoid confilcts
#include "camera_basler/CamGigEBasler.hpp"

namespace camera_basler
{

    class Task : public TaskBase
    {
	friend class TaskBase;

    public:
        /** TaskContext constructor for Task
         * \param name Name of the task. This name needs to be unique to make it identifiable via nameservices.
         */
        Task(std::string const& name = "camera_basler::Task");

        /** TaskContext constructor for Task 
         * \param name Name of the task. This name needs to be unique to make it identifiable for nameservices. 
         * \param engine The RTT Execution engine to be used for this task, which serialises the execution of all commands, programs, state machines and incoming events for a task. 
         */
        Task(std::string const& name, RTT::ExecutionEngine* engine);

        /** Default deconstructor of Task
         */
	    ~Task();

        /** This hook is called by Orocos when the state machine transitions
         * from PreOperational to Stopped. If it returns false, then the
         * component will stay in PreOperational. Otherwise, it goes into
         * Stopped.
         *
         * It is meaningful only if the #needs_configuration has been specified
         * in the task context definition with (for example):
         */
        bool configureHook();
    };

}  // namespace camera_basler

#endif  // CAMERA_BASLER_TASK_HPP

