# --- WARNING: WORK IN PROGRESS, THE CONTENTS OF THIS DOCUMENT MAY CHANGE ---
**24 Dec 2025: We're currently investigating an issue where creating and using a new material in your mod folder will cause a crash. As a workaround, we've found that using a material that's part of the Engine Content, such as BasicShapeMaterial or an instance of it, will work.**
**18 Dec 2025: You have to be on Beta channels (for both Steam and Quest platforms) to be able to try mod features.** 

# Paradiddle Workshop
Base project to create mods for Paradiddle. Includes an example mod. You can fork this repository or download the project as a zip file. 

## Description
This project was created to allow the Paradiddle Community to create mods to enhance their experience. We did our best to offer complete creative freedom with the least amount of constraints possible. With access to main features of the app, possible mod functionalities include but definitely are not limited to:
* Creating custom drums, that support multiple hit zones to make different voices
* Overriding the visuals of highway tracks and notes
* A new highway system
* New Environments
* Interactable Items, Props, FX
* Minigames to be played with drums
* Override Stick and Headset Visuals
* Functionality based on information retrieved online

## Required Installations and Setup

* **Unreal Engine:** Unreal Engine 5.4 has been used and it is recommended. You can go for newer versions if you are absolutely sure that there will be no compatibility issues. The simplest form of installation can be done following the guide from Epic: https://dev.epicgames.com/documentation/en-us/unreal-engine/installing-unreal-engine?application_version=5.4

* **Unreal Engine Requirements and Dependencies:** Unreal Engine has software and hardware requirements to run. Installing the matching Visual Studio version for example is important for the engine to run without issues. You can checkout Epic's documentation to make necessary adjustments and installations: https://dev.epicgames.com/documentation/en-us/unreal-engine/hardware-and-software-specifications-for-unreal-engine?application_version=5.4

* **Setting Up Unreal Engine for Android (Required only for Mobile platforms):**  Some additional steps have to be taken to prepare Unreal Engine to package content for Android platforms. Epic's guide: https://dev.epicgames.com/documentation/en-us/unreal-engine/set-up-android-sdk-ndk-and-android-studio-using-turnkey-for-unreal-engine?application_version=5.4

* **Download/Access Paradiddle Workshop:** You can fork this repository or download it in .zip format. (For newcomers: Click on the green "Code" button and select "Download ZIP" option). Try to keep your project directory (directory to which zip file will be extracted) length short as Unreal Engine's directory length limit might create issues that are hard to spot.

* **Build and Launch Paradiddle Workshop:** Please complate all the installations before moving to this step. Double click on the Unreal Engine project and select the Unreal Engine version you have installed if it prompts you. Unreal Engine will try to build and launch the project. If it fails, you may have to build it manually through your IDE.
  
## Getting Started

### Project Structure
This project was created using Unreal Engine 5.4. You'll need to install Unreal Engine with the matching version to open it and create mods that are comptaible with Paradiddle. Please note that even if the project loads without issues on a different version of Unreal Engine, any created mods might have compatibility issues with the main app. 
The project includes:
* An example mod that features simple versions of the application cases mentioned in the description. (Game/TestMod)
* An empty mod directory that can be renamed to serve as your mod. (Game/MyMod)
* Assets that are necessary to create mods and some mod features, classes to inherit from. (Game/Workshop)

### Mod File and Directory Structure
Unreal Engine uses .pak files to store and load assets at runtime. Thus, any mod content is expected to be stored in a .pak file. We currently do not support multiple .pak files for one mod, therefore any mod created for Paradiddle should comprise of a single .pak file. 

Any asset or class that is referenced in your mod should be packaged in the .pak file of your mod for it to run without issues. One exception to this, are the assets given in the Game/Workshop directory. These are common assets with the main application and don't need to be packaged along with your mod content. **If you are not experienced in creating and manipulating .pak files, we strongly recommend following the practices mentioned in Rules and Constraints part.**

The main application will search for mods at startup. The parent directory of mod content is the same with that of custom songs and drum layouts. For example, as custom songs are located under Documents/Paradiddle/Songs directory for Windows, mod content will be sought for in the driectory Documents/Paradiddle/Mods. 

### Rules and Constraints
Despite our best efforts to offer unhindered freedom, there are some rules and constraints that modders will have to abide by. Some of these have emerged due to Unreal Engine's structure, some of them originate from our implementation of modding infrastructure. 

* **Your Mod directory and .pak file should have the same name:** If you would like to name your Mod, "MyFantasticMod" it should be located in Paradiddle/Mods/MyFantasticMod and the content of the mod should be in a .pak file named MyFantasticMod.pak (Paradiddle/Mods/MyFantasticMod/MyFantasticMod.pak).
  
* **All your mod content should be located in the same directory and a data label should be used to tag this content for packaging:** This is to ensure that all the mod content gets packaged in the same .pak file. If you are familiar with .pak system and packaging you can go for an alternative approach **but following this guide is strongly recommended.** We utilize Data Asset Labels to tag assets to get packaged together. You can find one of these labels already created for you in Game/MyMod/MyModDataAssetLabel. Feel free to rename this and use it or create your own in your mod directory. Please note that this asset label should be located right under your main mod directory. Pushing it to any other subdirectories will cause issues. Some adjustment will have to be made after the creation of the label. 
<img width="1267" height="498" alt="image" src="https://github.com/user-attachments/assets/92c3a7d5-e644-4019-96f2-f0a8ca489b14" />

**1-Chunk ID:** The id to be used to tag assets that are going to be packaged together. You can use any positive integer other than 0 (Used for anything that is untagged) and 10 (used for the example mod)

**2-Cook Rule:**  Unreal Engine's automatic cook conditions can complicate your process. It is better and safer to use "Always cook"option.

**3-Label Assets in Directory:** Should be set to true as to get all assets under the directory labelled properly.

**4-Include Redirectors:**  It is better to avoid/clean up redirectors but they should be included if they exist.
If all these settings are done properly, your mod assets will get packaged in the same .pak file and will be available in the project directory once you package it. For example if you package you mod for Windows, you will find the .pak file of your mod in ProjectDirectory/ParadiddleWorkshop/Saved/StagedBuilds/Windows/ParadiddleWorkshop/Content/Paks/pakchunk<Chunk_ID>-Windows.pak. You can then rename this .pak file to comply with the naming convention given above.

* **There should be a Mod Manager Actor class in your main mod directory that complies with the naming convention:** We utilize a ModManagerActor (/Script/ModContent.ModManagerActor) class to allow hooking mod content to the main app. This class will be sought for by the main app once your mod gets loaded and an instance of this class will be created. The main app will then call an initialization function within this class to allow you to initialize your mod functionality. For all this to happen, a child class of this ModManagerActor class should be created in your main mod driectory (Game/MyMod) and it should be named <YourModName>ManagerActor, (i.e. for a mod named "MyWonderfulMod" this class should be named "MyWonderfulModManagerActor").
<img width="652" height="295" alt="image" src="https://github.com/user-attachments/assets/79b73c1d-0323-4348-af0b-f8781301dea4" />


* **Using ModData Data Asset as a container for you mod functionality:** Albeit being listed here, this is not compulsory. We have created a Data Asset to help modders keep references to essential assets in order. You can observe the usage of this in the example mod provided in the project.

* **Do not modify common classes:** Do not modify any of the classes provided in Game/Workshop. These do not get packaged with your mod content and any modifications will get lost and cause issues if they are referenced.

* **New C++ classes are not supported:** Due to packaging and safety issues we do not support adding C++ content through mods at the moment.

* **Do not modify render settings:** The shaders compiled for your mod should be usable by the main app. Many render settings affect shaders generated for Unreal Engine materials, thus changing them is likely to cause incompatibilites. We recommend not changing recnder settings unless you are certain that no compatibility issues will arise. 

### Creating Your First Mod

#### The Manager Actor:
The compulsory manager actor mentioned in the Rules and Constraints part handles the main functionality of your mod. It has class functions that get called by the main application when certain events occur. In the child class you will create, override these functions to handle the occurance of the pertaining event. You can find more information about these function in /Script/ModContent.ModManagerActor. 

#### Mod Communication Subsystem: 
This Game Instance Subsystem contains all the functionality you would use to interact with the main application. Once you create custom drums, you can request the main application to spawn them. You will also use this system to access the existing drums the player has created and stream in your custom level and a lot more. Find out more in Script/ModContent.ModCommunicationSubsystem.

#### UI Interactions: 
You can make any actor you create in your mode interactable with Paradiddle's UI. This means that these actors will be hovered on/off, grabbed and released. To do this you will have to implement the interaction interface we provide in the shared clasess and make the mesh/collider that is going to handle the interaction block the collision channel we use for laser interaction. This is done by requesting the collision channel through the communication subsystem and setting a response to it.
Here are some visuals from an example case you can find in Game/TestMod/Drums/TestMod_Snare:
<img width="1249" height="486" alt="image" src="https://github.com/user-attachments/assets/1b01ac2f-c2ec-45e8-b691-26e3e22e2447" />

Interface function implementations:

<img width="749" height="508" alt="image" src="https://github.com/user-attachments/assets/615ef120-800e-446e-80e8-4bdecfcca6f3" />

#### Creating New Environments
Paradiddle environments are simply Unreal Engine levels, thus any level of your design can be used as a new environment. 

Make sure to account for highway position if you would like songs to be played in your environmets. Do not load or stream your environments manually and use the Mod Communication Subsystem to call LoadModMap function instead. This will allow the main application to unload the existing level and prepare other assets for the new level. 

Some form of UI will be necessary to get the request from the user to load your environment. It is possible to create a UI window just like the ones you seen in Paradiddle and let this window carry a menu for your mod. The ways to do this will be explained later in this document. Instead of creating your own UI, you can also add your custom environments directly to Paradiddle's native environment list by calling AddModMapToMapList function from Mod Communication Subsystem. They will then appear in the environment menu and be chooseable by the users. 

You can find example implementations of both use cases in the example mod's menu widget: Game/TestMod/ModUI/ModMainMenuWidget

#### Mod UI and Creating A Paradiddle Window for Your Mod
For a mod with a single feature, you wouldn't have to come up with a UI solution since every mod gets assigned a toggle which can be used to switch this feature on and off. However, as your mod gets more sophisticated and content-rich you will have to let the users navigate through the mod content and make choices. You may use Unreal Engine's UI widgets for this purpose. Paradiddle's laser pointer will allow the user to hover over and click Unreal Engine buttons and use any other interactable similarly. You can find a menu built in the Test Mod. (ModMainMenuWidget)

Any menu or other form of UI should be accessible by the users. You can create interactable actors as mentioned previously and attach your UI assets to these actors. Users will then be able to grab and position you mod menu to their convenience. A more sophisticated solution is to access Paradiddle's Window class by inheriting from PDMUIWindowBase. This class allows you to place your mod assets on a Paradiddle window. An example application of this method can be found in TestMod (TestModMainUIActor).

It is also undesirable, especially in VR applications to have persistent UI elements. Thus, there should be a way to switch UI visibility. You can set HasSwitchableUI boolean to true in you Mod Manager class to have a UI switch button assigned to your mod. An event will then be called in your Mod Manager class whenever this button gets clicked. You can use this event to keep track of and adjust your UI visibility state.

#### Accessing Core Features 
The infrastructure we have created allows you to access core application features and make use of them. Most of these features and events such as drum hits, song creation, song completion can be accessed through the  Mod Communication Subsystem. Please refer to the source code for detailed explanations on how to subscribe to events and make use of features. 
Some simple examples can be given as follows:
* Bind to DrumHit delegate to create an environment that responds to the hits made by the player. (e.g. bursts of smoke changing color and density based on hit information)

  **Example Use Case 1**: In my mod level I would like to have dragons that breathe fire when a drum gets hit. Each dragon has an assigned drum. I listen to drum hits and make the matching dragon breathe fire when a drum gets hit.
  
* Bind to DrumCreated delegate to get notified when a drum gets created.
  
  **Example Use Case 1 Continued**: In order to make dragons breathe fire when a drum gets created, I have to create them first. In a manager class or equivalent, I listen to DrumCreated event and spawn a Dragon actor every time a drum gets creted.
  
* Bind to DrumRemoved delegate to get notified when a drum gets removed from the scene.
  **Example Use Case 1 Continued**: A level is only playable when good maintained. I don't want to keep unnecessary dragons for drums that don't exist anymore. I listen to DrumRemoved event and remove the dragons accordingly.

* Bind to SongCreated delegate to get notified when a song gets created (not started playing).
  
  **Example Use Case 2**: In my mod, I would like to build an environment where flowers blossom or wither based on my song performance. I listen to SongCreated event to prepare the environment, spawn any manager actors for the wither/blossom mechanic.
  
* Bind to SongFinished delegate to get notified when a song is completed.
  
  **Example Use Case 2 Continued**: I want a burst of particles to appear on the blossomed flowers when I finish the song to celebrate my success. I make my blossomed flowers listen to SongFinished event and spawn particles.
  
* Bind to SongDeleted delegate to get notified when the song gets deleted (song may nor may not have been completed)
  
  **Example Use Case 2 Continued**: I want to clear the environment after the song as to make it ready for another one. I listen to SongDeleted event and destroy all flowers and manager actors if there are any.
  
* Bind to FireModeSwithced delegate to get notified when the fire mode gets turned on/off.
  
  **Example Use Case 2 Continued**: I want my blossomed flowers to rotate when the player is "on fire" (achieved the required successful hit streak). I switch this functionality by making my blossomed flowers listen to FireModeSwitched.
  
* Bind to SongPauseSwitch delegate to get notified when a song gets paused/unpaused
  
  **Example Use Case 2 Continued**: I want to make my flowers look at the player when the song gets paused, as if they want to see what the player is up to in the middle of the song. I listen to this event to set a state for look direction.
  
* Bind to SongNoteHit delegate to get notified when a note gets hit successfuly or gets missed
  
  **Example Use Case 2 Continued**: I listen to this event to set the state of my flowers to be blossomed or withered.
  
* Bind to SongNoteHittable delegate to get notified when a note enters hit window (note that there is a time window, within which a note can be hit)
  
  **Example Use Case 2 Continued**: I would like the player to see the transition of flowers to the blossomed or withered state. In order to do this I have to spawn all flowers in a neutral state and let them transition when a note gets hit/missed. I listen to this event to spawn flowers in a neutral state.

#### Creating Custom Drums
To create a custom drum class, a child class of PDMDrumActorBase should be created. This base class allows your custom drum class to hook into Paradiddle's drum system. Hi-hats have an open-close mechanic and to address that another base class has been defined. Thus, to create a custom Hi-hat a child class of PDMHihatActor should be used. 

Once you create the custom class you need to make some adjustments for your drum to function properly: (TO BE CONTINUED) 
## -- to be updated --

