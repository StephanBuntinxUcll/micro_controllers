idf_component_register(SRCS "component_1.c"
                    INCLUDE_DIRS "include")

idf_component_register(SRCS "component_1.c"
                        INCLUDE_DIRS "include"
                        REQUIRES driver)