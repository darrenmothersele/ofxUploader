#ifndef __httpPOST__ofxUploader__
#define __httpPOST__ofxUploader__

#include "ofMain.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Base64Encoder.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/Net/StringPartSource.h"
#include "Poco/StreamCopier.h"
#include "Poco/Buffer.h"

class ofxUploader {
  Poco::Net::HTMLForm form;
  string hostname;
  string path;
  int port;
  
public:
  ofxUploader(string _h = "example.com", int _pt = 80, string _p = "/upload.php") 
  : hostname(_h), port(_pt), path(_p) {}
  
  void addSnapshot(string attr_name = "screenshot");
  void addItem(string attr_name, string attr_value);
  
  void send();
};


#endif /* defined(__httpPOST__ofxUploader__) */
