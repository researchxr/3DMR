FUNCTION(CreateWindowsBatchScript in out build_type)
  IF(VTK_DIR)
    SET(VTK_BIN_DIR "${VTK_DIR}/bin/${build_type}")
  ELSE()
    SET(VTK_BIN_DIR)
  ENDIF()
  
  SET(VS_BUILD_TYPE ${build_type})
  CONFIGURE_FILE(${in} ${out} @ONLY)
  # substitute again
  CONFIGURE_FILE(${out} ${out} @ONLY)
ENDFUNCTION()
