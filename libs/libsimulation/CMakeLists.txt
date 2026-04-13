add_library(simulation STATIC lsode.cc modeles.cc rk4.cc rocket.cc simulation.cc)
target_include_directories(simulation PUBLIC .)
