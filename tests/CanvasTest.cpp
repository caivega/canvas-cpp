
#include <tut/tut.hpp>
#include "Canvas.h"

using namespace canvas;

namespace tut
{
   struct CanvasData
   {
      CanvasData()
         : canvas(new Canvas(100, 100, Canvas::kARGB, false))
      { }
      
      ~CanvasData()
      {
         delete canvas;
      }
      
      Canvas  * canvas;
   };
   
   test_group<CanvasData> canvasTest("Canvas");
   typedef test_group<CanvasData>::object object;
   
   template <>
   template <>
   void object::test<1>()
   {
      set_test_name("Canvas allocation");
   }
   
   template <>
   template <>
   void object::test<2>()
   {
      set_test_name("Javascript Test 1");
      
      canvas->startWithCode("");
   }
   
   template <>
   template <>
   void object::test<3>()
   {
      set_test_name("Javascript Test 2: console.log()");
      
      canvas->startWithCode("console.log(\"Hello, World!\")");
      ensure(canvas->lastLogEntry() == "Hello, World!");
   }
   
   template <>
   template <>
   void object::test<4>()
   {
      set_test_name("Javascript Test 3: window.setInterval()");
      
      canvas->startWithCode("window.setInterval(function() { console.log(\"Hello, World!\"); });");
      ensure(canvas->lastLogEntry() == "");
      
      canvas->paint(0);
      canvas->paint(0);
      
      // After we have painter two times, we should have two "Hello, World!" messages in the history
      ensure(canvas->lastLogEntry() == "Hello, World!");
      ensure(canvas->lastLogEntry() == "Hello, World!");
      ensure(canvas->lastLogEntry() == "");
   }
   
   template <>
   template <>
   void object::test<5>()
   {
      set_test_name("Javascript Test 4: window.getContext('')");
      
      canvas->startWithCode("console.log(window.getContext('') == undefined ? 'True' : 'False')");
      ensure(canvas->lastLogEntry() == "True");
   }
   
   template <>
   template <>
   void object::test<6>()
   {
      set_test_name("Javascript Test 5: window.getContext('2d')");
      
      canvas->startWithCode("console.log(window.getContext('2d') != undefined ? 'True' : 'False')");
      ensure(canvas->lastLogEntry() == "True");
   }
   
   template <>
   template <>
   void object::test<7>()
   {
      set_test_name("Javascript Test 6: Test attribute lineWidth");
      
      canvas->startWithCode("var ctx = window.getContext('2d'); ctx.lineWidth = 2.0; console.log(ctx.lineWidth);");
      ensure(canvas->lastLogEntry() == "2");
   }
   
   template <>
   template <>
   void object::test<8>()
   {
      set_test_name("Javascript Test 7: Test attribute lineCap");
      
      canvas->startWithCode("var ctx = window.getContext('2d'); ctx.lineCap = 'round'; console.log(ctx.lineCap);");
      ensure(canvas->lastLogEntry() == "round");
   }
   
   template <>
   template <>
   void object::test<9>()
   {
      set_test_name("Javascript Test 8: width/height attributes");
      
      canvas->startWithCode("console.log(window.width); console.log(window.height);");
      ensure(canvas->lastLogEntry() == "100");
      ensure(canvas->lastLogEntry() == "100");
   }
}

