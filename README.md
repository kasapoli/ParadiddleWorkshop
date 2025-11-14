# Paradiddle Workshop
Base project to create mods for Paradiddle. Includes an example mod.

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

## Getting Started

### Project Structure
This project was created using Unreal Engine (See Version History for the current engine version). Unreal Engine with the mathcing version should be installed to run it and create mods that are comptaible with the main app. Please note that, even in case the project loads without issues on a different version of Unreal Engine, any created mod might have compatibility issues with the main app. 
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

* **Your Mod directory and .pak file should bare the same name:** If you would like to name your Mod, "MyFantasticMod" it should be located in Paradiddle/Mods/MyFantasticMod and the content of the mod should be in a .pak file named MyFantasticMod.pak (Paradiddle/Mods/MyFantasticMod/MyFantasticMod.pak).
  
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

Some form of UI will be necessary to get the request from the user to load your environment. It is possible to create a UI window just like the ones you seen in Paradiddle and let this window carry a menu for your mod. The ways to do this will be explained later in this document. Instead of creating oyur own UI, you can also add your custom environments directly to Paradiddle's native environment list by calling AddModMapToMapList function from Mod Communication Subsystem. They will then appear in the environment menu and be chooseable by the users. 

You can find example implementations of both use cases in the example mod's menu widget: Game/TestMod/ModUI/ModMainMenuWidget

#### Accessing Core Features and Utilizing Them (Minigames)
The infrastructure we have created allows you to access core application features and make use of them. Most of these features and events such as drum hits, song creation, song completion can be accessed through the  Mod Communication Subsystem. Please refer to the source code for detailed explanations on how to subscribe to events and make use of features. 


