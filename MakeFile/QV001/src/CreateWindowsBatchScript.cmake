#######################################################################
#
#  Copyright (c) 张晓东, 罗火灵. All rights reserved.
#  更多信息请访问: 
#    http://www.vtkchina.org (VTK中国)
#	http://blog.csdn.net/www_doling_net (东灵工作室) 
#
#######################################################################

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