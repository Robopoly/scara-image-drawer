PROJECT( edge_detection )
FIND_PACKAGE( OpenCV REQUIRED )
ADD_EXECUTABLE( edge edge.cpp )
TARGET_LINK_LIBRARIES( edge ${OpenCV_LIBS} )

