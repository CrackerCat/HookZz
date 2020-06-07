#include "dobby_internal.h"

#include "logging/logging.h"

#include "Interceptor.h"
#include "InterceptRouting/InterceptRouting.h"

#include "InterceptRoutingPlugin/DynamicBinaryInstrument/dynamic-binary-instrument.h"

PUBLIC int DobbyInstrument(void *inst_address, DBICallTy handler) {
  if (!inst_address)
    FATAL("[!] ERROR: the function address is 0x0.\n");

  DLOG("[*] Initialize 'DobbyInstrument' hook at %p\n", inst_address);

  Interceptor *interceptor = Interceptor::SharedInstance();

  HookEntry *entry           = new HookEntry();
  entry->id                  = interceptor->entries->getCount();
  entry->type                = kDynamicBinaryInstrument;
  entry->instruction_address = inst_address;

  DynamicBinaryInstrumentRouting *route = new DynamicBinaryInstrumentRouting(entry, (void *)handler);
  route->Dispatch();
  interceptor->AddHookEntry(entry);
  route->Commit();

  DLOG("[*] Finalize %p\n", inst_address);
  return RS_SUCCESS;
}
