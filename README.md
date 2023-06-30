# UNIQ
## Description
UNIQ is a simple usermode controller and kernelmode driver combo that hooks a native kernel function of your choice while allowing 2 way communication between the driver and the controller.

## Customizing
You can use the `common.h` file in the **UNIQWICU** project to change the various parameters such as the target process name, the function to hook, etc.
## Build
Make sure you have the [WDK](https://learn.microsoft.com/en-us/windows-hardware/drivers/download-the-wdk) installed (basically your Visual Studio IDE should have the Driver project template available).

Open the `UNIQ.sln` file in the root directory and build the solution in `Release` mode.
This will build both the UNIQWICK[ernel] and UNIQWICU[ser] projects.

*Note: Building the kernelmode driver (UNIQWICK[ernel]) in `Debug` mode will log debug messages to the kernel debugger.*
<br>

## Usage
After building you will have multiple files in the `x64/Release` (depending on your build config) directory.

### Kernelmode Driver
The kernel mode driver can be loaded using the `sc` command or by using a driver loader such as [OSR Driver Loader](https://www.osronline.com/article.cfm?article=157).

#### sc
You can load the driver using the `sc` command such as:
```
sc.exe create UNIQWICK binPath= "C:\Users\user\source\repos\UNIQ\x64\Release\UNIQWICK.sys" type= kernel

```
*Note: You will need to have [test signing mode](https://learn.microsoft.com/en-us/windows-hardware/drivers/install/the-testsigning-boot-configuration-option) enabled to load the driver using `Bcdedit.exe -set TESTSIGNING ON`.*

#### OSR Driver Loader
You can load the driver using [OSR Driver Loader](https://www.osronline.com/article.cfm?article=157) by selecting the driver file and clicking `Start Service`.

#### Manual Mapping
You can load the driver using manual mapping by using a tool such as [KDMapper](https://github.com/TheCruZ/kdmapper)

### Usermode Controller
The usermode controller can be run by simply double clicking the executable (in admin mode). Make sure the target process is running before starting the controller.

*Note: The controller will not work if the driver is not loaded.*

![img](https://i.imgur.com/qfBKz4r.png)