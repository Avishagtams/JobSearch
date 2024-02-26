cmake_minimum_required(VERSION 3.24)
project(part1)

set(CMAKE_CXX_STANDARD 17)

add_executable(part1 main.cpp Employer.cpp Employer.h Job.cpp Job.h JobSearchSystem.cpp JobSearchSystem.h user.cpp User.h Candidate.cpp Candidate.h)
