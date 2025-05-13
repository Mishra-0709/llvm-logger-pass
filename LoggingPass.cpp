#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Constants.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
struct LoggingPass : public FunctionPass {
  static char ID;
  LoggingPass() : FunctionPass(ID) {}

  bool runOnFunction(Function &F) override {
    LLVMContext &Ctx = F.getContext();
    Module *M = F.getParent();
    IRBuilder<> Builder(&F.getEntryBlock().front());

    // Create format string: "Entering <func>\n"
    std::string Msg = "Entering " + F.getName().str() + "\n";
    Constant *FormatStr = Builder.CreateGlobalStringPtr(Msg, "fmt");

    // Declare printf if not declared already
    FunctionCallee PrintfFunc = M->getOrInsertFunction(
        "printf",
        FunctionType::get(IntegerType::getInt32Ty(Ctx),
                          PointerType::get(Type::getInt8Ty(Ctx), 0),
                          true));

    Builder.CreateCall(PrintfFunc, FormatStr);

    return true;
  }
};
} // namespace

char LoggingPass::ID = 0;
static RegisterPass<LoggingPass> X("logfunc", "Insert printf at function entry");
