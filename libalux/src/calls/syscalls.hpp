#ifndef __LIBALUX_SYSCALLS_HPP__
#define __LIBALUX_SYSCALLS_HPP__

namespace libalux {

enum Syscalls {
  PrintSyscall,
  ExitSyscall,
  GetPidSyscall,
  GetUidSyscall,
  CountPageSizesSyscall,
  GetPageSizeSyscall,
  GetPageAlignSyscall,
  GetVMCapabilitiesSyscall,
  AllocateSyscall,
  FreeSyscall,
  GetNanoTimeSyscall
};

}

#endif
