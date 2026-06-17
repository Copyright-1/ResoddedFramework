# ResoddedFramework
ResoddedFramework is an open-source modding base for the game Plants vs. Zombies.  <br>  <br> 
It was based on version 0.9.9.1029 however features from future versions such as GOTY (EA Store) have been backported.
## Join the Discord

https://discord.gg/cK2ewgYQUe

# How To Use

1. Download [CMake](https://cmake.org/download/), [Git](https://git-scm.com/install/windows), [vcpkg](https://learn.microsoft.com/vcpkg/get_started/get-started) and [Visual Studio 2026](https://visualstudio.microsoft.com/downloads/) (or [other version](https://gist.github.com/Chenx221/6f4ed72cd785d80edb0bc50c9921daf7), 2019 work) or [Clang](https://releases.llvm.org/download.html) 
2. `git clone repo*` (*url to my fork or original)
3. Compile
    - **[For VS.](https://youtu.be/A3-GchLlZAo)**
    - **For clang:**
```ps
cd ResoddedFramework
cmake --preset windows-x64-debug-clang
cmake --build --preset windows-x64-debug-clang
```


## What I want to do in my fork:

- [ ] Change OpenAL to SDL_mixer.
- [ ] Change libvorbis to stb_vorbis.
- [ ] Change FreeType to stb_truetype.
- [ ] Change Bass.dll to libopenmpt (for Linux, MacOS, BSD-like etc.).
- [ ] Add support for other OSes (Linux, MacOS, BSD-like etc.)

# Roadmap original repo

### High Priority
- Reworked Rendering - 100%
- JSON Settings, replacing the registry - 100%
- ResourceGen V2 ([In Development](https://github.com/LawnProject/ResourceGen))
- Documentation - 1%
- Window Resizing - 100%
- Advanced Options - 100%
- UTF-8 Support - 100%
- MP3/OGG/FLAC Lawn Music - 100%
- Controller Support - 80% (Board Only)
### Low Priority
- Multi-platform support - 15%
- Separate mod resources (.pak + folders) - 100%
- Update Checker - 100%

# Credits

### Main

- [Electr0Gunner](https://github.com/Electr0Gunner) -> Creator, Lead Programmer
- [IsraelProyects](https://github.com/IsraelDXPP) -> Secondary Programmer, Fixes & Improvements
- [ThePixelMoon](https://github.com/ThePixelMoon) -> Project Setup + Structure

### Special Thanks

- niqkidd -> Name of the project
- [InLiothixie](https://github.com/InLiothixi) -> Zombatar Reverse Enginnering + Bug Fixes
- [Patoke](https://github.com/Patoke) -> Creator of [re-plants-vs-zombies](https://github.com/Patoke/re-plants-vs-zombies), a huge source of reference for reversed engineered code
- spaghetto207 -> LawnScrollbar implementation
- The original team behind the 0.9.9 decompilation

### Acknowledgements
- PopCap -> Franchise and Open-Source Engine
- Teams behind SDL, OpenAL-soft, Freetype, BASS, and other dependencies.
