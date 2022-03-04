# KeyAuth-CPP-Example

Based of off the original Keyauth C++ example : https://keyauth.win

### Features Added :
- Anti-DLL Injection
- Hide Thread Security protection
- Xor (XorStr function, used in the form : printf(xor("text")); )
- Print colour to console ( located in "print.cpp" and "print.h" )
- File organisation ( main.cpp is more organised, keyauth information stored in "keyauth.h", all functions/utils in files )
- Making functions global ( Improved only download function passing 2 parameters, dload("95192", "C://text.txt") , first is keyauth ID then location )

### Features that *may* come :
- Safer downloads of files ( Downloading from a server and destroying packets on download )
- Streaming files ( Stream files instead of directly downloading them )
- Using IsDebuggerPresent() function for additional security
- Implementation of IMGUI for a nicer interactive interface

If you enjoy this release feel free to star it 👍
