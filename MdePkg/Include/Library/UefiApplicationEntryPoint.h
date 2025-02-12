/** @file
  Module entry point library for UEFI Applications.

Copyright (c) 2007 - 2018, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __UEFI_APPLICATION_ENTRY_POINT_H__
#define __UEFI_APPLICATION_ENTRY_POINT_H__

///
/// Declare the EFI/UEFI Specification Revision to which this driver is implemented
///
extern CONST UINT32  _gUefiDriverRevision;

/**
  Entry point to UEFI Application.

  This function is the entry point for a UEFI Application. This function must call
  ProcessLibraryConstructorList(), ProcessModuleEntryPointList(), and ProcessLibraryDestructorList().
  The return value from ProcessModuleEntryPointList() is returned.
  If _gUefiDriverRevision is not zero and SystemTable->Hdr.Revision is less than _gUefiDriverRevison,
  then return EFI_INCOMPATIBLE_VERSION.

  @param  ImageHandle  The image handle of the UEFI Application.
  @param  SystemTable  A pointer to the EFI System Table.

  @retval  EFI_SUCCESS               The UEFI Application exited normally.
  @retval  EFI_INCOMPATIBLE_VERSION  _gUefiDriverRevision is greater than SystemTable->Hdr.Revision.
  @retval  Other                     Return value from ProcessModuleEntryPointList().

**/
NO_STACK_COOKIE // MU_CHANGE: Project Mu Runtime Randomized Stack Cookie Support
EFI_STATUS
EFIAPI
_ModuleEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  Required by the EBC compiler and identical in functionality to _ModuleEntryPoint().

  @param  ImageHandle  The image handle of the UEFI Application.
  @param  SystemTable  A pointer to the EFI System Table.

  @retval  EFI_SUCCESS               The UEFI Application exited normally.
  @retval  EFI_INCOMPATIBLE_VERSION  _gUefiDriverRevision is greater than SystemTable->Hdr.Revision.
  @retval  Other                     Return value from ProcessModuleEntryPointList().

**/
EFI_STATUS
EFIAPI
EfiMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  Invokes the library destructors for all dependent libraries and terminates
  the UEFI Application.

  This function calls ProcessLibraryDestructorList() and the EFI Boot Service Exit()
  with a status specified by Status.

  @param  Status  Status returned by the application that is exiting.

**/
VOID
EFIAPI
Exit (
  IN EFI_STATUS  Status
  );

/**
  Autogenerated function that calls the library constructors for all of the module's
  dependent libraries.

  This function must be called by _ModuleEntryPoint().
  This function calls the set of library constructors for the set of library instances
  that a module depends on. This includes library instances that a module depends on
  directly and library instances that a module depends on indirectly through other libraries.
  This function is autogenerated by build tools and those build tools are responsible for
  collecting the set of library instances, determine which ones have constructors, and
  calling the library constructors in the proper order based upon each of the library
  instances own dependencies.

  @param  ImageHandle  The image handle of the UEFI Application.
  @param  SystemTable  A pointer to the EFI System Table.

**/
VOID
EFIAPI
ProcessLibraryConstructorList (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  Autogenerated function that calls the library descructors for all of the module's
  dependent libraries.

  This function may be called by _ModuleEntryPoint()or Exit().
  This function calls the set of library destructors for the set of library instances
  that a module depends on.  This includes library instances that a module depends on
  directly and library instances that a module depends on indirectly through other libraries.
  This function is autogenerated by build tools and those build tools are responsible
  for collecting the set of library instances, determine which ones have destructors,
  and calling the library destructors in the proper order based upon each of the library
  instances own dependencies.

  @param  ImageHandle  The image handle of the UEFI Application.
  @param  SystemTable  A pointer to the EFI System Table.

**/
VOID
EFIAPI
ProcessLibraryDestructorList (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  This function calls the set of module entry points. It must be called by _ModuleEntryPoint().

  This function is autogenerated by build tools and those build tools are
  responsible for collecting the module entry points and calling them in a specified order.

  @param  ImageHandle    The image handle of the UEFI Application.
  @param  SystemTable    A pointer to the EFI System Table.

  @retval  EFI_SUCCESS   The UEFI Application executed normally.
  @retval  !EFI_SUCCESS  The UEFI Application failed to execute normally.

**/
EFI_STATUS
EFIAPI
ProcessModuleEntryPointList (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

#endif
