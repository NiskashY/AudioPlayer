# Audio Player
Desktop application. You can play tracks from your device, interact with folders, store compositions in account.

## Build 
<p>
    
    cmake -S . -B {dir_to_build}

    cmake --build {dir_to_build}

Example:

    cmake -S . -B build

    cmake --build build

</p>

## Application GUI

<p align="center">
    <img
        src = "docs/images/DownloadPage.png"
    >
    <br>
    Figure 1 - Download Page
</p>

On download page program search for files {.mp3, .wav} formats in specific direcotry: 

    1) The user can select it from his computer

    2) Or it is set at /path/to/app/saved-tracks/ 

<p align="center">
    <img
        src = "docs/images/LikedPage.png"
    >
    <br>
    Figure 2 - Liked Page
</p>


On 'Liked Tracks' page user can select tracks from server and receive them, if they doesn't located in selected directory

Data from server to client transfers via TCP/IP connection.


### The [docs](docs) directory contains a detailed desctiption of how the application works
