# Tutorial
Calculator's tutorial

 Here are sixth libraries that include the entire program, the first three are for release-Calculator.exe. It's just double click Calculator.exe to run Calculator.exe
 kernel in Desktop.
 * Qt5Core.dll
 * Qt5Gui.dll 
 * Qt5Widgets.dll
 
 
## The other three are for debug, if you want to test / build and run the program again.
* Qt5Cored.dll
* Qt5Guid.dll 
* Qt5Widgetsd.dll


## Differences between the sixth libraries are that debug projects have d.dll and releas projects have .dll.

# Här är stylesheet för kalkylatorn layout-design
# Stylesheet code for buttons

*Digits 0-9 Stylesheet*
QPushButton {
   border: 1px solid gray;
}
QPushButton:pressed {
    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,
                                      stop: 0 #dadbde, stop: 1 #f6f7fa);
}
*end Digits 0-9 Stylesheet*
*(Clear,+/-,%,. buttons) Unary Operations Buttons Stylesheet*
QPushButton {
  background-color: rgb(215, 215, 215);
  border: 1px solid gray;
}
QPushButton:pressed {
    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,
                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);
}
*end Unary Operations Buttons Stylesheet*
*(Orange buttons) Operations Buttons Stylesheet*
QPushButton {
  background-color: rgb(255, 151, 57);
  color: white;
  border: 1px solid gray;
}
QPushButton:pressed {
    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,
                                      stop: 0 #FF7832, stop: 1 #FF9739);
}
*(Label at top) Label Stylesheet*
QLabel {
  qproperty-alignment: 'AlignVCenter | AlignRight';
  border: 1px solid gray;
}
background-color : white;
*end Label Stylesheet*
