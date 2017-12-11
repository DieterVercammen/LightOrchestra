cordova.define('cordova/plugin_list', function(require, exports, module) {
module.exports = [
  {
    "id": "cordova-plugin-battery-status.battery",
    "file": "plugins/cordova-plugin-battery-status/www/battery.js",
    "pluginId": "cordova-plugin-battery-status",
    "clobbers": [
      "navigator.battery"
    ]
  },
  {
    "id": "cordova-plugin-bluetooth-serial.bluetoothSerial",
    "file": "plugins/cordova-plugin-bluetooth-serial/www/bluetoothSerial.js",
    "pluginId": "cordova-plugin-bluetooth-serial",
    "clobbers": [
      "window.bluetoothSerial"
    ]
  },
  {
    "id": "cordova-plugin-camera.Camera",
    "file": "plugins/cordova-plugin-camera/www/CameraConstants.js",
    "pluginId": "cordova-plugin-camera",
    "clobbers": [
      "Camera"
    ]
  },
  {
    "id": "cordova-plugin-camera.CameraPopoverOptions",
    "file": "plugins/cordova-plugin-camera/www/CameraPopoverOptions.js",
    "pluginId": "cordova-plugin-camera",
    "clobbers": [
      "CameraPopoverOptions"
    ]
  },
  {
    "id": "cordova-plugin-camera.camera",
    "file": "plugins/cordova-plugin-camera/www/Camera.js",
    "pluginId": "cordova-plugin-camera",
    "clobbers": [
      "navigator.camera"
    ]
  },
  {
    "id": "cordova-plugin-camera.CameraPopoverHandle",
    "file": "plugins/cordova-plugin-camera/www/CameraPopoverHandle.js",
    "pluginId": "cordova-plugin-camera",
    "clobbers": [
      "CameraPopoverHandle"
    ]
  },
  {
    "id": "cordova-plugin-contacts.contacts",
    "file": "plugins/cordova-plugin-contacts/www/contacts.js",
    "pluginId": "cordova-plugin-contacts",
    "clobbers": [
      "navigator.contacts"
    ]
  },
  {
    "id": "cordova-plugin-contacts.Contact",
    "file": "plugins/cordova-plugin-contacts/www/Contact.js",
    "pluginId": "cordova-plugin-contacts",
    "clobbers": [
      "Contact"
    ]
  },
  {
    "id": "cordova-plugin-contacts.ContactAddress",
    "file": "plugins/cordova-plugin-contacts/www/ContactAddress.js",
    "pluginId": "cordova-plugin-contacts",
    "clobbers": [
      "ContactAddress"
    ]
  },
  {
    "id": "cordova-plugin-contacts.ContactError",
    "file": "plugins/cordova-plugin-contacts/www/ContactError.js",
    "pluginId": "cordova-plugin-contacts",
    "clobbers": [
      "ContactError"
    ]
  },
  {
    "id": "cordova-plugin-contacts.ContactField",
    "file": "plugins/cordova-plugin-contacts/www/ContactField.js",
    "pluginId": "cordova-plugin-contacts",
    "clobbers": [
      "ContactField"
    ]
  },
  {
    "id": "cordova-plugin-contacts.ContactFindOptions",
    "file": "plugins/cordova-plugin-contacts/www/ContactFindOptions.js",
    "pluginId": "cordova-plugin-contacts",
    "clobbers": [
      "ContactFindOptions"
    ]
  },
  {
    "id": "cordova-plugin-contacts.ContactName",
    "file": "plugins/cordova-plugin-contacts/www/ContactName.js",
    "pluginId": "cordova-plugin-contacts",
    "clobbers": [
      "ContactName"
    ]
  },
  {
    "id": "cordova-plugin-contacts.ContactOrganization",
    "file": "plugins/cordova-plugin-contacts/www/ContactOrganization.js",
    "pluginId": "cordova-plugin-contacts",
    "clobbers": [
      "ContactOrganization"
    ]
  },
  {
    "id": "cordova-plugin-contacts.ContactFieldType",
    "file": "plugins/cordova-plugin-contacts/www/ContactFieldType.js",
    "pluginId": "cordova-plugin-contacts",
    "merges": [
      ""
    ]
  },
  {
    "id": "cordova-plugin-device.device",
    "file": "plugins/cordova-plugin-device/www/device.js",
    "pluginId": "cordova-plugin-device",
    "clobbers": [
      "device"
    ]
  },
  {
    "id": "cordova-plugin-device-motion.Acceleration",
    "file": "plugins/cordova-plugin-device-motion/www/Acceleration.js",
    "pluginId": "cordova-plugin-device-motion",
    "clobbers": [
      "Acceleration"
    ]
  },
  {
    "id": "cordova-plugin-device-motion.accelerometer",
    "file": "plugins/cordova-plugin-device-motion/www/accelerometer.js",
    "pluginId": "cordova-plugin-device-motion",
    "clobbers": [
      "navigator.accelerometer"
    ]
  },
  {
    "id": "cordova-plugin-device-orientation.CompassError",
    "file": "plugins/cordova-plugin-device-orientation/www/CompassError.js",
    "pluginId": "cordova-plugin-device-orientation",
    "clobbers": [
      "CompassError"
    ]
  },
  {
    "id": "cordova-plugin-device-orientation.CompassHeading",
    "file": "plugins/cordova-plugin-device-orientation/www/CompassHeading.js",
    "pluginId": "cordova-plugin-device-orientation",
    "clobbers": [
      "CompassHeading"
    ]
  },
  {
    "id": "cordova-plugin-device-orientation.compass",
    "file": "plugins/cordova-plugin-device-orientation/www/compass.js",
    "pluginId": "cordova-plugin-device-orientation",
    "clobbers": [
      "navigator.compass"
    ]
  },
  {
    "id": "cordova-plugin-dialogs.notification",
    "file": "plugins/cordova-plugin-dialogs/www/notification.js",
    "pluginId": "cordova-plugin-dialogs",
    "merges": [
      "navigator.notification"
    ]
  },
  {
    "id": "cordova-plugin-dialogs.notification_android",
    "file": "plugins/cordova-plugin-dialogs/www/android/notification.js",
    "pluginId": "cordova-plugin-dialogs",
    "merges": [
      "navigator.notification"
    ]
  }
];
module.exports.metadata = 
// TOP OF METADATA
{
  "cordova-plugin-battery-status": "1.1.2",
  "cordova-plugin-bluetooth-serial": "0.4.7",
  "cordova-plugin-camera": "2.1.1",
  "cordova-plugin-console": "1.0.7",
  "cordova-plugin-contacts": "2.0.1",
  "cordova-plugin-device": "1.1.7",
  "cordova-plugin-device-motion": "1.2.5",
  "cordova-plugin-device-orientation": "1.0.7",
  "cordova-plugin-dialogs": "1.2.1"
};
// BOTTOM OF METADATA
});