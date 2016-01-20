#include <pcd8544.h>
#include "pcd8544.h"

DECLARE(LCDInit);
// DECLARE(LCDcommand);
// DECLARE(LCDdata);
// DECLARE(LCDsetContrast);
DECLARE(LCDclear);
DECLARE(LCDdisplay);
// DECLARE(LCDsetPixel);
// DECLARE(LCDgetPixel);
// DECLARE(LCDfillcircle);
// DECLARE(LCDdrawcircle);
// DECLARE(LCDdrawrect);
// DECLARE(LCDfillrect);
// DECLARE(LCDdrawline);
// DECLARE(LCDsetCursor);
// DECLARE(LCDsetTextSize);
// DECLARE(LCDsetTextColor);
// DECLARE(LCDwrite);
// DECLARE(LCDshowLogo);
// DECLARE(LCDdrawchar);
DECLARE(LCDdrawstring);
// DECLARE(LCDdrawstring_P);
// DECLARE(LCDdrawbitmap);
// DECLARE(LCDspiwrite);
// DECLARE(shiftOut);
// DECLARE(_delay_ms);

IMPLEMENT(LCDInit) {
  SCOPE_OPEN();

  SET_ARGUMENT_NAME(0,SCLK);
  SET_ARGUMENT_NAME(1,DIN);
  SET_ARGUMENT_NAME(2,DC);
  SET_ARGUMENT_NAME(3,CS);
  SET_ARGUMENT_NAME(4,RST);
  SET_ARGUMENT_NAME(5,contrast);

  CHECK_ARGUMENTS_LENGTH_EQUAL(6);
  
  CHECK_ARGUMENT_TYPE_UINT32(0);
  CHECK_ARGUMENT_TYPE_UINT32(1);
  CHECK_ARGUMENT_TYPE_UINT32(2);
  CHECK_ARGUMENT_TYPE_UINT32(3);
  CHECK_ARGUMENT_TYPE_UINT32(4);
  CHECK_ARGUMENT_TYPE_UINT32(5);

  unsigned short SCLK = GET_ARGUMENT_AS_UINT32(0);
  unsigned short DIN = GET_ARGUMENT_AS_UINT32(1);
  unsigned short DC = GET_ARGUMENT_AS_UINT32(2);
  unsigned short CS = GET_ARGUMENT_AS_UINT32(3);
  unsigned short RST = GET_ARGUMENT_AS_UINT32(4);
  unsigned short contrast = GET_ARGUMENT_AS_UINT32(5);

  ::LCDInit(SCLK,DIN,DC,CS,RST,contrast);

  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(LCDclear){
    SCOPE_OPEN();
    
    CHECK_ARGUMENTS_LENGTH_EQUAL(0);
    
    ::LCDclear();
    
    SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(LCDdisplay){
    SCOPE_OPEN();
    
    CHECK_ARGUMENTS_LENGTH_EQUAL(0);
    
    ::LCDdisplay();
    
    SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(LCDdrawstring) {
    SCOPE_OPEN();

    SET_ARGUMENT_NAME(0, x);
    SET_ARGUMENT_NAME(1, line);
    SET_ARGUMENT_NAME(2, c);

    CHECK_ARGUMENTS_LENGTH_EQUAL(3);

    CHECK_ARGUMENT_TYPE_INT32(0);
    CHECK_ARGUMENT_TYPE_INT32(1);
    CHECK_ARGUMENT_TYPE_STRING(2);

    int x = GET_ARGUMENT_AS_INT32(0);
    int line = GET_ARGUMENT_AS_INT32(1);
    #if NODE_VERSION_AT_LEAST(0, 11, 0)
      v8::String::Utf8Value c(GET_ARGUMENT_AS_STRING(2));
    #else
      v8::String::AsciiValue c(GET_ARGUMENT_AS_STRING(2));
    #endif

    ::LCDdrawstring(x, line, *c);

    SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT_EXPORT_INIT(pcd8544) {
  EXPORT_FUNCTION(LCDInit);
  EXPORT_FUNCTION(LCDclear);
  EXPORT_FUNCTION(LCDdisplay);
  EXPORT_FUNCTION(LCDdrawstring);
}

