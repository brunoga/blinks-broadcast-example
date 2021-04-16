#ifndef MESSAGE_HANDLERS_H_
#define MESSAGE_HANDLERS_H_

#include <blinklib.h>

#define MESSAGE_COUNT_BLINKS 1
#define MESSAGE_REPORT_BLINKS_COUNT 2

extern byte message_payload[];

void rcv_message_handler(byte message_id, byte src_face, byte* payload,
                         bool loop);

byte fwd_message_handler(byte message_id, byte src_face, byte dst_face,
                         byte* payload);

void rcv_reply_handler(byte message_id, byte src_face, const byte* payload);

byte fwd_reply_handler(byte message_id, byte dst_face, byte* payload);

#endif
