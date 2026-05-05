# WackyDist

**WackyDist** is a custom audio effect plugin built in **C++** using the **JUCE** framework. WackyDist offers unique distortion & grit, adding character to samples / audio.
__

Compatible with VST3 and AU hosts.

## Repository Structure
This repository contains the essential "DNA" of the plugin. Build folders and binaries are excluded (lightweight repo):
* `/Source`: All `.cpp` and `.h` files containing the DSP logic and UI components.
* `WackyDist.jucer`: The Projucer configuration file.

---

## How to Rebuild
To run or edit this project, you will need to regenerate the build files for your specific operating system.

### Prerequisites
1.  **JUCE Framework:** Download the latest version from [juce.com](https://juce.com/download/).
2.  **IDE:** * **macOS:** Xcode 

### Build Steps
1.  **Clone the Repo:**
    ```bash
    git clone [https://github.com/your-username/WackyDist.git](https://github.com/your-username/WackyDist.git)
    ```
2.  **Open the Jucer File:**
    Launch the JUCE Projucer and open `WackyDist.jucer`.
3.  **Configure Paths:**
    Ensure your "Global Paths" in the Projucer point to your local JUCE folder if the modules appear missing.
4.  **Export & Build:**
    * Click **"Save and Open in IDE"** to generate your Xcode or Visual Studio project.
    * Inside the IDE, select your target (e.g., VST3) and build the solution.

---

## Technical Specs
* **Language:** C++17
* **Framework:** JUCE
* **Category:** Distortion / FX
