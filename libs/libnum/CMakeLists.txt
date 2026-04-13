add_library(num STATIC lu.c rk4.c rkf.c general.c print.c sec.c newton.c ptfix.c sysnewton.c trapeze.c simpson.c spline.c)
target_include_directories(num PUBLIC include)
