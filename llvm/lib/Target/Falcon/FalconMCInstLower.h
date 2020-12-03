//===-- FalconMCInstLower.h - Lower MachineInstr to MCInst ------*- C++ -*-===//
//
// Part of the LLVM fork for the Mirage project, under the Apache License v2.0
// with LLVM Exceptions. See https://llvm.org/LICENSE.txt for license
// information.
// SPDX-License-Identifier: Apache-2.0 with LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TARGET_FALCON_MCINST_LOWER_H
#define LLVM_TARGET_FALCON_MCINST_LOWER_H

#include "llvm/Support/Compiler.h"

namespace llvm {

class AsmPrinter;
class MachineInstr;
class MachineOperand;
class MCContext;
class MCInst;
class MCOperand;
class MCSymbol;

/// Lowers `MachineInstr` objects into `MCInst` objects.
class FalconMCInstLower {
public:
  FalconMCInstLower(MCContext &Ctx, AsmPrinter &Printer);

  // Lower MachineInstr MI to MCInst OutMI.
  void lowerInstruction(const MachineInstr &MI, MCInst &OutMI) const;
  MCOperand lowerSymbolOperand(const MachineOperand &MO, MCSymbol *Sym) const;

private:
  MCContext &Ctx;
  AsmPrinter &AsmPrinter;
};

} // end namespace llvm

#endif // LLVM_TARGET_FALCON_MCINST_LOWER_H
