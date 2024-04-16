# Netrunner Card Finder
### C++ Hack Sprint ~ Spring 2024

### **README UNDER CONSTRUCTION**
#### Confirmed supported only under GNU/Linux OS at this time.
### Requirements:
- `GNU Make`
- `CMake 3.5+`
- `Qt5/Qt6`
- `libcurl`
- `simdjson` (included)

#### If using `image_grabber.py` to download cards.json data or card images:
- `Python 3.11+` with `json`, `pathlib`, `socket`, and `urllib` libraries

###### Compiled and tested with GCC v13.2.1 (20230801).
### Easy compilation:
#### Navigate to repository root directory and run the following command:
```
cmake -S ./ -B nrcf
make -C nrcf
```
#### Run executable by entering the following command:
```
./ncrf/netrunner_card_finder
```
#### OR locate the executable file within preferred file explorer GUI at above location (./ being the root of the repository) and launch.
