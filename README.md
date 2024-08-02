# Charger Detector

## 📕・Description

This project provides a solution to detect when a charger is connected to a computer, even when the computer is in sleep mode. Upon detection, a sound is played to notify the user. The service is configured to run in the background using systemd, with the capability to handle events even during sleep.

## 📦・Prerequisites

- Linux with systemd configured.
- Terminal access with administrator privileges.
- A functional audio device.

## ⌨️・・Steps to Install and Configure the Service

1. Clone the Repository and Compile the Program

Clone the project repository and compile the program using make:

```bash
git clone https://github.com/UgolinOlle/charger-detector.git
cd charger-detector
make install
```

2. Configure the systemd Service

The service is configured to run under systemd as a user service. Once installed, it can be enabled and started with the following commands:

```bash
systemctl --user enable charger-detector.service
systemctl --user start charger-detector.service
```

3. Check the Service Status

You can verify if the service is running correctly with:

```bash
systemctl --user status charger-detector.service
```

4. Test the Program

Plug in the charger to verify that the program plays a sound upon detection. If the sound is not played, ensure that your audio system is functional and that the service is active.
Additional Resources

- Official systemd Documentation
- Mac Power Management Guide

Feel free to customize this program to suit your specific needs, including setting up custom sounds or adding additional features.

## 🧑‍🤝‍🧑・Contributing

Contributions to the Charger Detector project are welcome. If you encounter any issues or wish to improve the code, feel free to open a pull request or an issue.

## 📑・License

This project is licensed under the MIT License - see the [LICENSE](./LICENSE) file for details.

## 📩・Contact

For any questions or collaboration, feel free to contact us via [email](mailto:hello@ugolin-olle.com) or
[LinkedIn](https://linkedin.com/in/ugolin-olle).
