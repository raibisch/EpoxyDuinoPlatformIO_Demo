

It took some attempts to run EpoxyDuino in PlatformIO (as extention of VS-Code) but now it works without problems.
Regarding the '*ino' vs '*.cpp' ist is very easy: keep the standard PlatformIO folder-stucture and rename your 'src/main.cpp' in '/src/mymain.cpp' 
```
#include <Arduino.h>
int i=0;
void setup() {
  Serial.println("***START***");
}

void loop() {
  Serial.printf("Hello %d\r\n",i);
  i++;
  delay(500);
}
```

...and here my 'platform.ini' file:
```
[env:native]
platform = native

build_flags =
    -DEPOXY_DUINO
    -DEPOXY_CORE_ESP8266
  
lib_deps:
 https://github.com/bxparks/EpoxyDuino.git
```

the definition of the compiler switch 'EPOXY_DUINO' is important to use the predefined main-loop in the existing 'main.cpp', the 'EXOXY_CORE_ESP8255' is optional for ESP simulation.
the 'lib_deps' definition automatic download the ExpoxyDuino-files from github

...that’s all ! (no further download or installation, no make file, or any other modification)
