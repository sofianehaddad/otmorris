

ot_add_current_dir_to_include_dirs ()

ot_add_source_file ( MyClass.cxx )
ot_add_source_file ( MyClassImplementation.cxx )

ot_install_header_file ( MyClass.hxx )
ot_install_header_file ( MyClassImplementation.hxx )


include_directories ( ${INTERNAL_INCLUDE_DIRS} )

add_library ( ottemplate ${SOURCEFILES} )
if ( BUILD_SHARED_LIBS )
  set_target_properties ( ottemplate PROPERTIES COMPILE_DEFINITIONS "OTTEMPLATE_DLL_EXPORTS" )
endif ()

if ( NOT DEFINED LIB_VERSION ) 
  set ( LIB_VERSION 0.0.0 )
endif ()
if ( NOT DEFINED LIB_SOVERSION ) 
  set ( LIB_SOVERSION 0 )
endif ()
set_target_properties ( ottemplate PROPERTIES VERSION ${LIB_VERSION} )
set_target_properties ( ottemplate PROPERTIES SOVERSION ${LIB_SOVERSION} )
target_link_libraries (ottemplate ${OPENTURNS_LIBRARY})

# Add targets to the build-tree export set
export (TARGETS ottemplate FILE ${PROJECT_BINARY_DIR}/OTTemplate-Targets.cmake)

# Install the export set for use with the install-tree
install(EXPORT OTTemplate-Targets
        DESTINATION "${OTTEMPLATE_CONFIG_CMAKE_PATH}"
        COMPONENT Development)

install(TARGETS ottemplate
        EXPORT  OTTemplate-Targets 
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION ${OTTEMPLATE_LIBRARY_PATH}
        ARCHIVE DESTINATION ${OTTEMPLATE_LIBRARY_PATH}
)

