# Paradiddle Workshop
Base project to create mods for Paradiddle. Includes an example mod.

## Description
This project was created to allow the Paradiddle Community to create mods to enhance their experience. We did our best to offer complete creative freedom with the least amount of constraints possible. With access to main features of the app, possible mod functonalities include but definitely are note limited to:
* Creating custom drums, that support multiple hit zones to make different voices
* Overriding the visuals of highway tracks and notes
* A new highway system
* New Environments
* Interactable Items, Props, FX
* Minigames to be played with drums
* Override Stick and Headset Visuals

## Getting Started

### Project Structure
This project was created using Unreal Engine (See Version History for the current engine version). Unreal Engine with the mathcing version should be installed to run it and create mods that are comptaible with the main app. Please note that, even in case the project loads without issues on a different version of Unreal Engine, any created mod might have compatibility issues with the main app. 
The project includes:
* An example mod that features simple versions of the application cases mentioned in the description. (Game/TestMod)
* An empty mod directory that can be renamed to serve as your mod. (Game/MyMod)
* Assets that are necessary to create mods and some mod features, classes to inherit from. (Game/Workshop)

### Mod File and Driectory Structure
Unreal Engine uses .pak files to store and load assets at runtime. Thus, any mod content is expected to be stored in a .pak file. We currently do not support multiple .pak files for one mod, therefore any mod created for Paradiddle should comprise of a single .pak file. 

Any asset or class that is referenced in your mod should be packaged in the .pak file of your mod for it to run without issues. One exception to this, are the assets given in the Game/Workshop directory. These are common assets with the main application and don't need to be packaged along with your mod content. **If you are not experienced in creating and manipulating .pak files, we strongly recommend following the practices mentioned in Rules and Constraints part.**

The main application will search for mods at startup. The parent directory of mod content is the same with that of custom songs and drum layouts. For example, as custom songs are located under Documents/Paradiddle/Songs directory for Windows, mod content will be sought for in the driectory Documents/Paradiddle/Mods. 

### Rules and Constraints
Despite our best efforts to offer unhindered freedom, there are some rules and constraints that modders will have to abide by. Some of these have emerged due to Unreal Engine's structure, some of them originate from our implementation of modding infrastructure. 

* **Your Mod directory and .pak file should bare the same name:** If you would like to name your Mod, "MyFantasticMod" it should be located in Paradiddle/Mods/MyFantasticMod and the content of the mod should be in a .pak file named MyFantasticMod.pak (Paradiddle/Mods/MyFantasticMod/MyFantasticMod.pak).
* **All your mod content should be located in the same directory and a data label should be used to tag this content for packaging:**
