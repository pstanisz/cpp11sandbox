ADD_LIBRARY(
    Singleton 
    threadsafesingleton.cc
)

TARGET_LINK_LIBRARIES(
    Singleton
    pthread
)

