#include "ofxUploader.h"

void ofxUploader::addItem(string attr_name, string attr_value) {
  form.add(attr_name, attr_value);
}

void ofxUploader::addSnapshot(string attr_name) {
  ofImage screenImg;
  screenImg.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
  screenImg.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
  ofBuffer buffer;
  ofSaveImage(screenImg.getPixelsRef(), buffer, OF_IMAGE_FORMAT_JPEG, OF_IMAGE_QUALITY_BEST);
  stringstream ss;
  Poco::Base64Encoder b64enc(ss);
  b64enc << buffer;
  form.add(attr_name, ss.str());
}

void ofxUploader::send() {
  Poco::Net::HTTPClientSession s(hostname, port);
  Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_POST, path);
  form.prepareSubmit(request);
  ostream& send = s.sendRequest(request);
  form.write(send);
  Poco::Net::HTTPResponse response;
  istream& res = s.receiveResponse(response);
  ostringstream stream;
  Poco::StreamCopier::copyStream(res, stream);
  cout << stream.str() << endl;
  form.clear();
}
