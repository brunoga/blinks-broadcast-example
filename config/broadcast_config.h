#ifndef BROADCAST_CONFIG_H_
#define BROADCAST_CONFIG_H_

#include "../message_handlers.h"

#define BROADCAST_MESSAGE_PAYLOAD_BYTES 15

#define BROADCAST_RCV_MESSAGE_HANDLER rcv_message_handler
#define BROADCAST_FWD_MESSAGE_HANDLER fwd_message_handler
#define BROADCAST_RCV_REPLY_HANDLER rcv_reply_handler
#define BROADCAST_FWD_REPLY_HANDLER fwd_reply_handler

#endif  // BROADCAST_CONFIG_H_
