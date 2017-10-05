#include "Task.hpp"

namespace camera_basler
{

    Task::Task(std::string const& name) :
        TaskBase(name)
    {
    }

    Task::Task(std::string const& name, RTT::ExecutionEngine* engine) :
        TaskBase(name, engine)
    {
    }

    Task::~Task()
    {
    }

    bool Task::configureHook()
    {
        if (! TaskBase::configureHook())
            return false;

        return true;
    }

}  // namespace camera_basler

