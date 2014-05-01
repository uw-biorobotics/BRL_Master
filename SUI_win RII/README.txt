
--------------------------------------------------------------------------
Surgeon User Interfase (SUI_win RII)
 Readme 14-Jun-2012
--------------------------------------------------------------------------

This is the Surgeons User Interface, surgeon's side software for running the BRL Surgical Robot.  The surgeon's side code is composed of two components:

1. "Omni Client" runs the main servo loop, communicates with the Phantom, and sends data to the surgical robot.  
2."GUI Server" is the surgeon's interface to the system.



For more info, visit:
http://brl.ee.washington.edu/ravenIIwiki/index.php/Main_Page


---------------------------------------------------------------------------
System Requirements
---------------------------------------------------------------------------
The SUI_win RII requires certain software and hardware components to be able to work properly. Those components are as follows.

Software:
---------
The following software must be installed for the SUI to work:
 

1. Visual Studio 2010
2. OpenHaptics SDK
3. QT SDK with MinGW
 

Hardware:
---------
 
1. Two Phantom Omnis configured as "Omni_Left" and "Omni_Right". (This can be setup using "Phantom Configuration" panel.)
2. The computer dedicated to running the SUI should be a "strong system", with a fast (1.2+ GHz) processor.





---------------------------------------------------------------------------Running the Application
---------------------------------------------------------------------------



1. Start the omni_client: 
 
*Your_path_to_SUI_win RII*\SUI_win RII\Omni_Client\Release\x64\Omni_Client.exe
2. Start the GUI
 Server: 
*Your_path_to_SUI_win RII*\SUI_win RII\VS_GUI_SERVER\release\GUI_Server.exe

3. Enter your passcode in the GUI login screen (1, 12, 123, and 1234 are testing logins)
4. 

Select the Surgical Robot's IP address from the "Engineer" tab.

5. 
To begin operation press "READY".



Remark 1: The code was compiled under Windows 7, using Microsoft Development Environment 2010 v.10.0.40219. It should not be necessary to recompile the SUI code.

 However, in the case you have to, here are some steps that may help doing so:
1. Add the QT SDK to the PATH environment variable
2. Define a new environment variable QTDIR, pointing to the folder msvc2010 of the QT SDK (e.g., *your_path_to_QTSDK*\Desktop\Qt\4.8.1\msvc2010

Remark 2: Without a properly configured footpedal, you can use the keyboard instead.
 Pedal-down state press the "d" key.
  Pedal-up state press the "e" key.

  In pedal-down state surgeon's motion will be transmitted to the slave robot.
 In pedal-up state no motion commands are sent.

The Phantom button controls the robot's grasp/cut action.  Press to grasp, release button to release  grasp.



Remark 3: Scaling: use the Scale selector to set the motion scaling factor in  percentage units.

To quit the Omni_Client press ^C.



---------------------------------------------------------------------------
Configuration
---------------------------------------------------------------------------
If a new slave-side IP address is required change "SUI_win/GUI_Server_Test_Main/Configuration/IPSetting.inf".  
The easiest/safest thing to do is replace one server line with the new address. The format is 

<entry_name> <1st octet> <2nd> <3rd> <4th>

With the four address octets separated by spaces.

---------------------------------------------------------------------------
Known Issues 
---------------------------------------------------------------------------

1. When you press the button to grasp the "ready" button turns red and says "E-STOP".  It is lying.  Red means "grasping"

. 

2. When quitting the application, if the GUI is closed before the Omni_Client the  message "unable to send_tcp" will be repeated.  Press ^C to stop this output.

 

3.  The "Elapsed Surgery Time" dialog  does not accurately reflect the time spent in the current session.


---------------------------------------------------------------------------

Contact

---------------------------------------------------------------------------
This is a rough overview of the SUI_win RII setup and operation.  

For more information contact Hawkeye King <hawkeye1@u.washington.edu>.


Created 14 June 2012.
