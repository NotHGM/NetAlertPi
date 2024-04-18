# NetAlertPi

NetAlertPi is an open-source project designed to monitor network connectivity by pinging a specified IP address or URL and triggering visual and auditory alerts when the connection fails. This project uses a Raspberry Pi and Arduino Uno to manage connectivity checks and to control the alerts, making it ideal for network administrators, developers, or anyone needing reliable network monitoring in small to medium network environments.

## Features

- **Continuous Monitoring**: Pings a predefined IP or URL at regular intervals to check connectivity.
- **Auditory Alerts**: Activates a buzzer when the connection is lost.
- **Visual Alerts**: Flashes LEDs to visually signal the loss of connectivity.
- **Scalable**: Supports multiple alert mechanisms and can be expanded with additional sensors or indicators.
- **DIY Friendly**: Leverages common components and open-source software, making it accessible for DIY enthusiasts.

## Components Needed

- Raspberry Pi (any model with network capability, Pi 5 recommended)
- Arduino Uno Rev3
- Buzzer
- LEDs
- Resistors (220 ohms for LEDs)
- Jumper wires
- Breadboard (optional but recommended for prototyping)

## Setup

### Hardware Assembly

1. Connect LEDs and a buzzer to the Arduino according to the pin assignments detailed in the project documentation.
2. Connect the Arduino Uno to the Raspberry Pi via a USB cable for serial communication.

### Software Installation

1. Install Raspberry Pi OS on your Raspberry Pi and set it up with network access.
2. Install Python and necessary libraries (`pyserial` for communication).
3. Load the provided Arduino sketch onto the Arduino Uno using the Arduino IDE.

### Configuration

- Edit the Python script to specify the IP address or URL you want to monitor.
- Adjust the polling frequency as needed.

## Usage

Run the Python script from your Raspberry Pi. The script will monitor the connection to the specified address. If the connection fails, the Raspberry Pi will signal the Arduino to activate the alerts.

## Contributing

Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

Distributed under the MIT License. See `LICENSE` for more information.

## Contact

George - [George@hgmartist.net](mailto:george@hgmartist.net)

Feel free to modify this template to better fit your project's context or add any additional sections that could be beneficial like 'Known Issues', 'Future Plans', or 'Technical Details'.
