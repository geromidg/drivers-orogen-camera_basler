#!/usr/bin/env ruby

require 'orocos'
require 'vizkit'

include Orocos

Orocos.initialize

Orocos.run 'camera_basler::Task' => 'gige_camera' do
    camera = Orocos::TaskContext.get 'gige_camera'

    camera.configure
    camera.start
    # camera.log_all_ports

    Vizkit.display camera.frame
    Vizkit.exec
end

