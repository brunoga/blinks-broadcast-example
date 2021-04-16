#include <blinklib.h>
#include <shared/blinkbios_shared_functions.h>
#include <string.h>

#include "message_handlers.h"
#include "src/blinks-broadcast/manager.h"
#include "src/blinks-broadcast/message.h"
#include "src/blinks-debug/debug.h"

broadcast::Message count_blinks;
broadcast::Message report_blinks;

void setup() {
  broadcast::message::Initialize(&count_blinks, MESSAGE_COUNT_BLINKS, false);
  memcpy(count_blinks.payload, message_payload,
         BROADCAST_MESSAGE_PAYLOAD_BYTES);

  broadcast::message::Initialize(&report_blinks, MESSAGE_REPORT_BLINKS_COUNT,
                                 true);
}

bool reported_blinks = false;
byte step = 0;
broadcast::Message result;
byte count = 0;

void loop() {
  broadcast::manager::Process();

  if (buttonSingleClicked()) {
    step = 1;
    count = 1;
  }

  switch (step) {
    case 0:
      return;
    case 1:
      if (!broadcast::manager::Send(&count_blinks)) return;
      break;
    case 2:
      if (!broadcast::manager::Receive(&result)) return;
      break;
    case 3:
      LOGF("Number of blinks (counted): ");
      LOGLN(result.payload[0]);
      break;
    case 4:
      report_blinks.payload[0] = result.payload[0];
      if (!broadcast::manager::Send(&report_blinks)) return;
      break;
  }

  step++;

  if (step > 4) {
    count++;
    if (count > 3) {
      step = 0;
      count = 0;
    } else {
      step = 1;
    }
  }
}
