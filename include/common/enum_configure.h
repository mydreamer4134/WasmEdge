// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2022 Second State INC

//===-- wasmedge/common/enum_configure.h - Configure related enumerations -===//
//
// Part of the WasmEdge Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the definitions of configure related enumerations.
///
//===----------------------------------------------------------------------===//

#ifndef WASMEDGE_C_API_ENUM_CONFIGURE_H
#define WASMEDGE_C_API_ENUM_CONFIGURE_H

#if (defined(__cplusplus) && __cplusplus > 201402L) ||                         \
    (defined(_MSVC_LANG) && _MSVC_LANG > 201402L)
#include "dense_enum_map.h"
#include <cstdint>
#include <string_view>
#endif

#if (defined(__cplusplus) && __cplusplus > 201402L) ||                         \
    (defined(_MSVC_LANG) && _MSVC_LANG > 201402L)
namespace WasmEdge {

/// WASM Proposal C++ enumeration class.
enum class Proposal : uint8_t {
  ImportExportMutGlobals = 0,
  NonTrapFloatToIntConversions,
  SignExtensionOperators,
  MultiValue,
  BulkMemoryOperations,
  ReferenceTypes,
  SIMD,
  TailCall,
  MultiMemories,
  Annotations,
  Memory64,
  ExceptionHandling,
  Threads,
  FunctionReferences,
  Max
};

static inline constexpr auto ProposalStr = []() constexpr {
  using namespace std::literals::string_view_literals;
  std::pair<Proposal, std::string_view> Array[] = {
      {Proposal::ImportExportMutGlobals, "Import/Export of mutable globals"sv},
      {Proposal::NonTrapFloatToIntConversions,
       "Non-trapping float-to-int conversions"sv},
      {Proposal::SignExtensionOperators, "Sign-extension operators"sv},
      {Proposal::MultiValue, "Multi-value returns"sv},
      {Proposal::BulkMemoryOperations, "Bulk memory operations"sv},
      {Proposal::ReferenceTypes, "Reference types"sv},
      {Proposal::SIMD, "Fixed-width SIMD"sv},
      {Proposal::TailCall, "Tail call"sv},
      {Proposal::MultiMemories, "Multiple memories"sv},
      {Proposal::Annotations, "Custom Annotation Syntax in the Text Format"sv},
      {Proposal::Memory64, "Memory64"sv},
      {Proposal::ExceptionHandling, "Exception handling"sv},
      {Proposal::Threads, "Threads"sv},
      {Proposal::FunctionReferences, "Typed Function References"sv},
  };
  return DenseEnumMap(Array);
}
();

} // namespace WasmEdge
#endif

/// WASM Proposal C enumeration.
enum WasmEdge_Proposal {
  WasmEdge_Proposal_ImportExportMutGlobals = 0,
  WasmEdge_Proposal_NonTrapFloatToIntConversions,
  WasmEdge_Proposal_SignExtensionOperators,
  WasmEdge_Proposal_MultiValue,
  WasmEdge_Proposal_BulkMemoryOperations,
  WasmEdge_Proposal_ReferenceTypes,
  WasmEdge_Proposal_SIMD,
  WasmEdge_Proposal_TailCall,
  WasmEdge_Proposal_MultiMemories,
  WasmEdge_Proposal_Annotations,
  WasmEdge_Proposal_Memory64,
  WasmEdge_Proposal_ExceptionHandling,
  WasmEdge_Proposal_Threads,
  WasmEdge_Proposal_FunctionReferences
};

#if (defined(__cplusplus) && __cplusplus > 201402L) ||                         \
    (defined(_MSVC_LANG) && _MSVC_LANG > 201402L)
namespace WasmEdge {

/// Host Module Registration C++ enumeration class.
enum class HostRegistration : uint8_t { Wasi = 0, WasmEdge_Process, Max };

} // namespace WasmEdge
#endif

/// Host Module Registration C enumeration.
enum WasmEdge_HostRegistration {
  WasmEdge_HostRegistration_Wasi = 0,
  WasmEdge_HostRegistration_WasmEdge_Process
};

/// AOT compiler optimization level C enumeration.
enum WasmEdge_CompilerOptimizationLevel {
  // Disable as many optimizations as possible.
  WasmEdge_CompilerOptimizationLevel_O0 = 0,
  // Optimize quickly without destroying debuggability.
  WasmEdge_CompilerOptimizationLevel_O1,
  // Optimize for fast execution as much as possible without triggering
  // significant incremental compile time or code size growth.
  WasmEdge_CompilerOptimizationLevel_O2,
  // Optimize for fast execution as much as possible.
  WasmEdge_CompilerOptimizationLevel_O3,
  // Optimize for small code size as much as possible without triggering
  // significant incremental compile time or execution time slowdowns.
  WasmEdge_CompilerOptimizationLevel_Os,
  // Optimize for small code size as much as possible.
  WasmEdge_CompilerOptimizationLevel_Oz
};

/// AOT compiler output binary format C enumeration.
enum WasmEdge_CompilerOutputFormat {
  // Native dynamic library format.
  WasmEdge_CompilerOutputFormat_Native = 0,
  // WebAssembly with AOT compiled codes in custom sections.
  WasmEdge_CompilerOutputFormat_Wasm
};

#endif // WASMEDGE_C_API_ENUM_CONFIGURE_H
