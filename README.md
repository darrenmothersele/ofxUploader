# ofxUploader

An openFrameworks addon for posting data to a webpage. Data can be added from
strings or by taking a snapshot of the screen and attaching as a base64
encoded image.

## Usage

Include the addon in your project, then initialise an instance of the uploader
in your app class:

    #include "ofxUploader.h"

    class testApp : public ofBaseApp{

      ofxUploader uploader;

      public:
        testApp() : uploader("example.com", 80, "/upload.php") {}
    };

Then simply add items to the uploader (optionally a screenshot) and
call the `send()` method to post the form data to the address you previously
specified in the constructor. For example:

    void testApp::keyPressed(int key){
      if (key == 'a') {
        stringstream ss;
        ss << "a random number is " << ofRandom(255) << endl;
        uploader.addItem("random", ss.str());
        uploader.addSnapshot();
        uploader.send();
      }
    }

