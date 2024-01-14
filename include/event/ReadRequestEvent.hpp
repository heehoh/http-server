#ifndef READREQUESTEVENT_HPP
#define READREQUESTEVENT_HPP

#include "AEvent.hpp"

class ReadRequestEvent : public AEvent
{
  private:
    Request mRequest;
    std::string mStringBuffer;
    std::string mFilePrefix;
    int mFileSize;
    std::string mMimeType;
    std::string mRedirectionPath;
    int getErrorPageFd(const LocationBlock &lb, int status);
    int getIndexFd(const LocationBlock &lb, int &stauts);
    int getFileFd(int &status);
    int getRequestFd(const LocationBlock &lb, int &status);
    void setFilePrefix(const LocationBlock &lb);
    std::string getFileExtension(const std::string &path);
    void makeWriteEvent(int &status);
    void makeReadFileEvent(int fd);

    void makeResponse(const LocationBlock &lb, int &status);
    int checkRequestError(const LocationBlock &lb);
    int checkRequestStartLine(const LocationBlock &lb);
    int checkRequestHeader(const LocationBlock &lb);
    int checkRequestBody(const LocationBlock &lb);

		bool checkCgiEvent(const LocationBlock &lb);
    void makeCgiEvent(const std::string &lbCgiPath);

  public:
    ReadRequestEvent(const Server &server, int clientSocket);
    virtual ~ReadRequestEvent();
    virtual void handle();
};

#endif