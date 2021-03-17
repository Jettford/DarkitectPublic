# Install script for directory: F:/Darkitect/External/PhysX/physx/source/compiler/cmake

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "F:/Darkitect/External/PhysX/physx/install/vc15win64/PhysX")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/source/foundation/include/windows" TYPE FILE FILES
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/windows/PsWindowsAoS.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/windows/PsWindowsFPU.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/windows/PsWindowsInclude.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/windows/PsWindowsInlineAoS.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/windows/PsWindowsIntrinsics.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/windows/PsWindowsTrigConstants.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/windows/PxWindowsIntrinsics.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/windows" TYPE FILE FILES "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/windows/PxWindowsIntrinsics.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/unix/PxUnixIntrinsics.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/unix" TYPE FILE FILES "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/unix/PxUnixIntrinsics.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysXFoundation_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysXFoundation_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysXFoundation_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysXFoundation_64.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "F:/Darkitect/External/PhysX/physx/include/PxFoundation.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/foundation" TYPE FILE FILES
    "F:/Darkitect/External/PhysX/physx/include/foundation/PxAssert.h"
    "F:/Darkitect/External/PhysX/physx/include/foundation/PxFoundationConfig.h"
    "F:/Darkitect/External/PhysX/physx/include/foundation/PxMathUtils.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/source/foundation/include" TYPE FILE FILES
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/Ps.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsAlignedMalloc.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsAlloca.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsAllocator.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsAoS.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsArray.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsAtomic.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsBasicTemplates.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsBitUtils.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsBroadcast.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsCpu.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsFoundation.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsFPU.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsHash.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsHashInternals.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsHashMap.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsHashSet.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsInlineAllocator.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsInlineAoS.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsInlineArray.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsIntrinsics.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsMathUtils.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsMutex.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsPool.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsSList.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsSocket.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsSort.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsSortInternals.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsString.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsSync.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsTempAllocator.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsThread.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsTime.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsUserAllocated.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsUtilities.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsVecMath.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsVecMathAoSScalar.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsVecMathAoSScalarInline.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsVecMathSSE.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsVecMathUtilities.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsVecQuat.h"
    "F:/Darkitect/External/PhysX/physx/source/foundation/include/PsVecTransform.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/Px.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxAllocatorCallback.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxProfiler.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxSharedAssert.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxBitAndData.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxBounds3.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxErrorCallback.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxErrors.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxFlags.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxIntrinsics.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxIO.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxMat33.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxMat44.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxMath.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxMemory.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxPlane.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxPreprocessor.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxQuat.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxSimpleTypes.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxStrideIterator.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxTransform.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxUnionCast.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxVec2.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxVec3.h;F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation/PxVec4.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "F:/Darkitect/External/PhysX/physx/install/vc15win64/PxShared/include/foundation" TYPE FILE FILES
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/Px.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxAllocatorCallback.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxProfiler.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxSharedAssert.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxBitAndData.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxBounds3.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxErrorCallback.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxErrors.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxFlags.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxIntrinsics.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxIO.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxMat33.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxMat44.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxMath.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxMemory.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxPlane.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxPreprocessor.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxQuat.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxSimpleTypes.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxStrideIterator.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxTransform.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxUnionCast.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxVec2.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxVec3.h"
    "F:/Darkitect/External/PhysX/physx/../pxshared/include/foundation/PxVec4.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/gpu" TYPE FILE FILES "F:/Darkitect/External/PhysX/physx/include/gpu/PxGpu.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cudamanager" TYPE FILE FILES
    "F:/Darkitect/External/PhysX/physx/include/cudamanager/PxCudaContextManager.h"
    "F:/Darkitect/External/PhysX/physx/include/cudamanager/PxCudaMemoryManager.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/common/windows" TYPE FILE FILES "F:/Darkitect/External/PhysX/physx/include/common/windows/PxWindowsDelayLoadHook.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysX_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysX_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysX_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysX_64.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "F:/Darkitect/External/PhysX/physx/include/PxActor.h"
    "F:/Darkitect/External/PhysX/physx/include/PxAggregate.h"
    "F:/Darkitect/External/PhysX/physx/include/PxArticulationReducedCoordinate.h"
    "F:/Darkitect/External/PhysX/physx/include/PxArticulationBase.h"
    "F:/Darkitect/External/PhysX/physx/include/PxArticulation.h"
    "F:/Darkitect/External/PhysX/physx/include/PxArticulationJoint.h"
    "F:/Darkitect/External/PhysX/physx/include/PxArticulationJointReducedCoordinate.h"
    "F:/Darkitect/External/PhysX/physx/include/PxArticulationLink.h"
    "F:/Darkitect/External/PhysX/physx/include/PxBatchQuery.h"
    "F:/Darkitect/External/PhysX/physx/include/PxBatchQueryDesc.h"
    "F:/Darkitect/External/PhysX/physx/include/PxBroadPhase.h"
    "F:/Darkitect/External/PhysX/physx/include/PxClient.h"
    "F:/Darkitect/External/PhysX/physx/include/PxConstraint.h"
    "F:/Darkitect/External/PhysX/physx/include/PxConstraintDesc.h"
    "F:/Darkitect/External/PhysX/physx/include/PxContact.h"
    "F:/Darkitect/External/PhysX/physx/include/PxContactModifyCallback.h"
    "F:/Darkitect/External/PhysX/physx/include/PxDeletionListener.h"
    "F:/Darkitect/External/PhysX/physx/include/PxFiltering.h"
    "F:/Darkitect/External/PhysX/physx/include/PxForceMode.h"
    "F:/Darkitect/External/PhysX/physx/include/PxImmediateMode.h"
    "F:/Darkitect/External/PhysX/physx/include/PxLockedData.h"
    "F:/Darkitect/External/PhysX/physx/include/PxMaterial.h"
    "F:/Darkitect/External/PhysX/physx/include/PxPhysics.h"
    "F:/Darkitect/External/PhysX/physx/include/PxPhysicsAPI.h"
    "F:/Darkitect/External/PhysX/physx/include/PxPhysicsSerialization.h"
    "F:/Darkitect/External/PhysX/physx/include/PxPhysicsVersion.h"
    "F:/Darkitect/External/PhysX/physx/include/PxPhysXConfig.h"
    "F:/Darkitect/External/PhysX/physx/include/PxPruningStructure.h"
    "F:/Darkitect/External/PhysX/physx/include/PxQueryFiltering.h"
    "F:/Darkitect/External/PhysX/physx/include/PxQueryReport.h"
    "F:/Darkitect/External/PhysX/physx/include/PxRigidActor.h"
    "F:/Darkitect/External/PhysX/physx/include/PxRigidBody.h"
    "F:/Darkitect/External/PhysX/physx/include/PxRigidDynamic.h"
    "F:/Darkitect/External/PhysX/physx/include/PxRigidStatic.h"
    "F:/Darkitect/External/PhysX/physx/include/PxScene.h"
    "F:/Darkitect/External/PhysX/physx/include/PxSceneDesc.h"
    "F:/Darkitect/External/PhysX/physx/include/PxSceneLock.h"
    "F:/Darkitect/External/PhysX/physx/include/PxShape.h"
    "F:/Darkitect/External/PhysX/physx/include/PxSimulationEventCallback.h"
    "F:/Darkitect/External/PhysX/physx/include/PxSimulationStatistics.h"
    "F:/Darkitect/External/PhysX/physx/include/PxVisualizationParameter.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/common" TYPE FILE FILES
    "F:/Darkitect/External/PhysX/physx/include/common/PxBase.h"
    "F:/Darkitect/External/PhysX/physx/include/common/PxCollection.h"
    "F:/Darkitect/External/PhysX/physx/include/common/PxCoreUtilityTypes.h"
    "F:/Darkitect/External/PhysX/physx/include/common/PxMetaData.h"
    "F:/Darkitect/External/PhysX/physx/include/common/PxMetaDataFlags.h"
    "F:/Darkitect/External/PhysX/physx/include/common/PxPhysicsInsertionCallback.h"
    "F:/Darkitect/External/PhysX/physx/include/common/PxPhysXCommonConfig.h"
    "F:/Darkitect/External/PhysX/physx/include/common/PxRenderBuffer.h"
    "F:/Darkitect/External/PhysX/physx/include/common/PxSerialFramework.h"
    "F:/Darkitect/External/PhysX/physx/include/common/PxSerializer.h"
    "F:/Darkitect/External/PhysX/physx/include/common/PxStringTable.h"
    "F:/Darkitect/External/PhysX/physx/include/common/PxTolerancesScale.h"
    "F:/Darkitect/External/PhysX/physx/include/common/PxTypeInfo.h"
    "F:/Darkitect/External/PhysX/physx/include/common/PxProfileZone.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pvd" TYPE FILE FILES
    "F:/Darkitect/External/PhysX/physx/include/pvd/PxPvdSceneClient.h"
    "F:/Darkitect/External/PhysX/physx/include/pvd/PxPvd.h"
    "F:/Darkitect/External/PhysX/physx/include/pvd/PxPvdTransport.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/collision" TYPE FILE FILES "F:/Darkitect/External/PhysX/physx/include/collision/PxCollisionDefs.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/solver" TYPE FILE FILES "F:/Darkitect/External/PhysX/physx/include/solver/PxSolverDefs.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "F:/Darkitect/External/PhysX/physx/include/PxConfig.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysXCharacterKinematic_static_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysXCharacterKinematic_static_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysXCharacterKinematic_static_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysXCharacterKinematic_static_64.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/characterkinematic" TYPE FILE FILES
    "F:/Darkitect/External/PhysX/physx/include/characterkinematic/PxBoxController.h"
    "F:/Darkitect/External/PhysX/physx/include/characterkinematic/PxCapsuleController.h"
    "F:/Darkitect/External/PhysX/physx/include/characterkinematic/PxController.h"
    "F:/Darkitect/External/PhysX/physx/include/characterkinematic/PxControllerBehavior.h"
    "F:/Darkitect/External/PhysX/physx/include/characterkinematic/PxControllerManager.h"
    "F:/Darkitect/External/PhysX/physx/include/characterkinematic/PxControllerObstacles.h"
    "F:/Darkitect/External/PhysX/physx/include/characterkinematic/PxExtended.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysXCommon_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysXCommon_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysXCommon_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysXCommon_64.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/geometry" TYPE FILE FILES
    "F:/Darkitect/External/PhysX/physx/include/geometry/PxBoxGeometry.h"
    "F:/Darkitect/External/PhysX/physx/include/geometry/PxCapsuleGeometry.h"
    "F:/Darkitect/External/PhysX/physx/include/geometry/PxConvexMesh.h"
    "F:/Darkitect/External/PhysX/physx/include/geometry/PxConvexMeshGeometry.h"
    "F:/Darkitect/External/PhysX/physx/include/geometry/PxGeometry.h"
    "F:/Darkitect/External/PhysX/physx/include/geometry/PxGeometryHelpers.h"
    "F:/Darkitect/External/PhysX/physx/include/geometry/PxGeometryQuery.h"
    "F:/Darkitect/External/PhysX/physx/include/geometry/PxHeightField.h"
    "F:/Darkitect/External/PhysX/physx/include/geometry/PxHeightFieldDesc.h"
    "F:/Darkitect/External/PhysX/physx/include/geometry/PxHeightFieldFlag.h"
    "F:/Darkitect/External/PhysX/physx/include/geometry/PxHeightFieldGeometry.h"
    "F:/Darkitect/External/PhysX/physx/include/geometry/PxHeightFieldSample.h"
    "F:/Darkitect/External/PhysX/physx/include/geometry/PxMeshQuery.h"
    "F:/Darkitect/External/PhysX/physx/include/geometry/PxMeshScale.h"
    "F:/Darkitect/External/PhysX/physx/include/geometry/PxPlaneGeometry.h"
    "F:/Darkitect/External/PhysX/physx/include/geometry/PxSimpleTriangleMesh.h"
    "F:/Darkitect/External/PhysX/physx/include/geometry/PxSphereGeometry.h"
    "F:/Darkitect/External/PhysX/physx/include/geometry/PxTriangle.h"
    "F:/Darkitect/External/PhysX/physx/include/geometry/PxTriangleMesh.h"
    "F:/Darkitect/External/PhysX/physx/include/geometry/PxTriangleMeshGeometry.h"
    "F:/Darkitect/External/PhysX/physx/include/geometry/PxBVHStructure.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/geomutils" TYPE FILE FILES
    "F:/Darkitect/External/PhysX/physx/include/geomutils/GuContactBuffer.h"
    "F:/Darkitect/External/PhysX/physx/include/geomutils/GuContactPoint.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysXCooking_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysXCooking_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysXCooking_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysXCooking_64.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cooking" TYPE FILE FILES
    "F:/Darkitect/External/PhysX/physx/include/cooking/PxBVH33MidphaseDesc.h"
    "F:/Darkitect/External/PhysX/physx/include/cooking/PxBVH34MidphaseDesc.h"
    "F:/Darkitect/External/PhysX/physx/include/cooking/Pxc.h"
    "F:/Darkitect/External/PhysX/physx/include/cooking/PxConvexMeshDesc.h"
    "F:/Darkitect/External/PhysX/physx/include/cooking/PxCooking.h"
    "F:/Darkitect/External/PhysX/physx/include/cooking/PxMidphaseDesc.h"
    "F:/Darkitect/External/PhysX/physx/include/cooking/PxTriangleMeshDesc.h"
    "F:/Darkitect/External/PhysX/physx/include/cooking/PxBVHStructureDesc.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysXExtensions_static_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysXExtensions_static_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysXExtensions_static_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysXExtensions_static_64.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/extensions" TYPE FILE FILES
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxBinaryConverter.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxBroadPhaseExt.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxCollectionExt.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxConstraintExt.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxContactJoint.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxConvexMeshExt.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxD6Joint.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxD6JointCreate.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxDefaultAllocator.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxDefaultCpuDispatcher.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxDefaultErrorCallback.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxDefaultSimulationFilterShader.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxDefaultStreams.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxDistanceJoint.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxContactJoint.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxExtensionsAPI.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxFixedJoint.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxJoint.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxJointLimit.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxMassProperties.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxPrismaticJoint.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxRaycastCCD.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxRepXSerializer.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxRepXSimpleType.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxRevoluteJoint.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxRigidActorExt.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxRigidBodyExt.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxSceneQueryExt.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxSerialization.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxShapeExt.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxSimpleFactory.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxSmoothNormals.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxSphericalJoint.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxStringTableExt.h"
    "F:/Darkitect/External/PhysX/physx/include/extensions/PxTriangleMeshExt.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/filebuf" TYPE FILE FILES "F:/Darkitect/External/PhysX/physx/include/filebuf/PxFileBuf.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysXVehicle_static_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysXVehicle_static_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysXVehicle_static_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysXVehicle_static_64.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vehicle" TYPE FILE FILES
    "F:/Darkitect/External/PhysX/physx/include/vehicle/PxVehicleComponents.h"
    "F:/Darkitect/External/PhysX/physx/include/vehicle/PxVehicleDrive.h"
    "F:/Darkitect/External/PhysX/physx/include/vehicle/PxVehicleDrive4W.h"
    "F:/Darkitect/External/PhysX/physx/include/vehicle/PxVehicleDriveNW.h"
    "F:/Darkitect/External/PhysX/physx/include/vehicle/PxVehicleDriveTank.h"
    "F:/Darkitect/External/PhysX/physx/include/vehicle/PxVehicleNoDrive.h"
    "F:/Darkitect/External/PhysX/physx/include/vehicle/PxVehicleSDK.h"
    "F:/Darkitect/External/PhysX/physx/include/vehicle/PxVehicleShaders.h"
    "F:/Darkitect/External/PhysX/physx/include/vehicle/PxVehicleTireFriction.h"
    "F:/Darkitect/External/PhysX/physx/include/vehicle/PxVehicleUpdate.h"
    "F:/Darkitect/External/PhysX/physx/include/vehicle/PxVehicleUtil.h"
    "F:/Darkitect/External/PhysX/physx/include/vehicle/PxVehicleUtilControl.h"
    "F:/Darkitect/External/PhysX/physx/include/vehicle/PxVehicleUtilSetup.h"
    "F:/Darkitect/External/PhysX/physx/include/vehicle/PxVehicleUtilTelemetry.h"
    "F:/Darkitect/External/PhysX/physx/include/vehicle/PxVehicleWheels.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/source/fastxml/include" TYPE FILE FILES "F:/Darkitect/External/PhysX/physx/source/fastxml/include/PsFastXml.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysXPvdSDK_static_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysXPvdSDK_static_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysXPvdSDK_static_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysXPvdSDK_static_64.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysXTask_static_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysXTask_static_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysXTask_static_64.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE FILE OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysXTask_static_64.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/task" TYPE FILE FILES
    "F:/Darkitect/External/PhysX/physx/include/task/PxCpuDispatcher.h"
    "F:/Darkitect/External/PhysX/physx/include/task/PxTask.h"
    "F:/Darkitect/External/PhysX/physx/include/task/PxTaskDefine.h"
    "F:/Darkitect/External/PhysX/physx/include/task/PxTaskManager.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysXFoundation_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysXFoundation_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysXFoundation_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysXFoundation_64.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE SHARED_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysXFoundation_64.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE SHARED_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysXFoundation_64.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE SHARED_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysXFoundation_64.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE SHARED_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysXFoundation_64.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysX_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysX_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysX_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysX_64.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE SHARED_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysX_64.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE SHARED_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysX_64.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE SHARED_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysX_64.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE SHARED_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysX_64.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE STATIC_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysXCharacterKinematic_static_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE STATIC_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysXCharacterKinematic_static_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE STATIC_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysXCharacterKinematic_static_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE STATIC_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysXCharacterKinematic_static_64.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE STATIC_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysXPvdSDK_static_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE STATIC_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysXPvdSDK_static_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE STATIC_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysXPvdSDK_static_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE STATIC_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysXPvdSDK_static_64.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysXCommon_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysXCommon_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysXCommon_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysXCommon_64.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE SHARED_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysXCommon_64.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE SHARED_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysXCommon_64.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE SHARED_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysXCommon_64.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE SHARED_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysXCommon_64.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysXCooking_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysXCooking_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysXCooking_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysXCooking_64.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE SHARED_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysXCooking_64.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE SHARED_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysXCooking_64.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE SHARED_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysXCooking_64.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE SHARED_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysXCooking_64.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE STATIC_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysXExtensions_static_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE STATIC_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysXExtensions_static_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE STATIC_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysXExtensions_static_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE STATIC_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysXExtensions_static_64.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE STATIC_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysXVehicle_static_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE STATIC_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysXVehicle_static_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE STATIC_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysXVehicle_static_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE STATIC_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysXVehicle_static_64.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/debug" TYPE STATIC_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysXTask_static_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Cc][Hh][Ee][Cc][Kk][Ee][Dd])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/checked" TYPE STATIC_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/checked/PhysXTask_static_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Pp][Rr][Oo][Ff][Ii][Ll][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/profile" TYPE STATIC_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/profile/PhysXTask_static_64.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/win.x86_64.vc142.mt/release" TYPE STATIC_LIBRARY FILES "F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/release/PhysXTask_static_64.lib")
  endif()
endif()

