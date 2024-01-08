#ifndef AEVENT_HPP
#define AEVENT_HPP

#include "Request.hpp"
#include "Response.hpp"
#include "Server.hpp"

#define EVENT_FINISH true
#define EVENT_CONTINUE false
#define BUFFER_SIZE 32768

class AEvent
{
  protected:
    Response mResponse;
    Request mRequest;
    const Server &mServer;
    int mClientSocket;

  public:
    AEvent(const Server &server);
    AEvent(const Server &server, int clientSocket);
    virtual ~AEvent();
    virtual void handle() = 0;
};

#endif