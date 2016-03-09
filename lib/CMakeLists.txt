
add_subdirectory ( include )
add_subdirectory ( src )
add_subdirectory ( test )

install ( FILES ${HEADERFILES}
  DESTINATION ${OTMORRIS_INCLUDE_PATH}/${PACKAGE_NAME}
        )

