/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Logger.cpp
Project:    CS230 Engine
Author:     Jonathan Holmes, Hankyung Lee
Created:    March 8, 2023
Updated:    March 20, 2023
*/

#include <iostream>
#include "Logger.h"

CS230::Logger::Logger(Logger::Severity severity, bool use_console, std::chrono::system_clock::time_point start_time)
    : min_level(severity), out_stream("Trace.log"), start_time(start_time) {
    if (use_console == true) {
        out_stream.set_rdbuf(std::cout.rdbuf());
    }
}

CS230::Logger::~Logger() {
    out_stream.flush();
    out_stream.close();
}

void CS230::Logger::log(CS230::Logger::Severity severity, std::string message) {

    std::string severity_level_string = "";
    switch (severity) {
    case Severity::Verbose:
        severity_level_string = "Verbose";
        break;
    case Severity::Debug:
        severity_level_string = "Debug";
        break;
    case Severity::Event:
        severity_level_string = "Event";
        break;
    case Severity::Error:
        severity_level_string = "Error";
        break;
    }

    bool should_print = (min_level <= severity) ? true : false;

    if (should_print) {
        out_stream.precision(4);
        out_stream << '[' << std::fixed << seconds_since_start() << "]\t";
        out_stream << severity_level_string << "\t" << message << "\n";
    }
    else {
        return;
    }
    
    return;
}

double CS230::Logger::seconds_since_start() {
    return std::chrono::duration<double>( std::chrono::system_clock::now() - start_time ).count();
}