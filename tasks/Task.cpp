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

    Task::~Task(void)
    {
    }

    bool Task::configureHook(void)
    {
        if (!TaskBase::configureHook())
            return false;

        camera::CamGigEBasler* cam_gige_basler;

        try
        {
            // TODO: Use shared pointer
            cam_gige_basler = new camera::CamGigEBasler();

            RTT::log(RTT::Info) << "Initialized camera." << RTT::endlog();
        }
        catch (std::runtime_error e)
        {
            RTT::log(RTT::Error) << "Failed to initialize camera: " << e.what() << RTT::endlog();

            return false;
        }

        cam_gige_basler->setCameraSize(_width, _height);

        cam_interface = cam_gige_basler;

        return true;
    }

}  // namespace camera_basler

