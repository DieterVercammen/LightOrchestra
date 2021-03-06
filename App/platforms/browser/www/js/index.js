

'use strict';
var accelerationX = 0;
var accelerationY = 0;
var accelerationZ = 0;
var X;
$('#stop_strumming').hide();
$("#start").click(function(){

    $("#start").fadeOut('slow');  

});

var app = {

    initialize: function () {
        document.addEventListener('deviceready', this.onDeviceReady.bind(this), false);
        this.bindEvents();
    },
    bindEvents: function() {
        document.addEventListener('deviceready', app.onDeviceReady, false);
      },

    onDeviceReady: function () {
        
        app.goTo('paired-devices');
        

        bluetoothSerial.isEnabled(app.listPairedDevices, function () {
            app.showError('Enable bluetooth')
        });
        
        
       
        $('#refresh-paired-devices').click(app.listPairedDevices);
        $('#paired-devices form').submit(app.selectDevice);
        $('#toggle-connection').click(app.toggleConnection);
        $('#clear-data').click(app.clearData);
        
        $('#terminal form').submit(app.sendData);
        $('#startAcc').click(app.startWatch());

        $('#terminal .go-back').click(function () {
            app.goTo('paired-devices');
        });
        app.receivedEvent('deviceready');
        
        
    },
    

    listPairedDevices: function () {
        bluetoothSerial.list(function (devices) {
           
            var $list = $('#paired-devices .list');

            if (!devices.length) {
                $list.text('Not found');
                return;
            }

            $list.text('');
            devices.forEach(function (device) {
                $list.append('<label><input type="radio" name="device" value="' + device.address +
                    '"><div><span class="name">' + device.name + '</span> <span class="address">' + device.address +
                    '</span></div></label>');
            });

        }, app.showError);
    },

    selectDevice: function (event) {
        event.preventDefault();

        var $label = $('#paired-devices .list input[name=device]:checked').parent();

        var name = $label.find('.name').text();
        var address = $label.find('input').val();

        if (!address) {
            app.showError('Select paired device to connect');
            return;
        }

        app.goTo('terminal');

        var $selectedDevice = $('#selected-device');
        $selectedDevice.find('.name').text(name);
        $selectedDevice.find('.address').text(address);

        app.connect(address);
    },

    toggleConnection: function () {
        bluetoothSerial.isConnected(
            // Disconnect if connected
            function () {
                bluetoothSerial.disconnect(app.deviceDisconnected, app.showError);
            },

            // Reconnect to selected device if disconnected
            function () {
                var address = $('#selected-device .address').text();

                if (!address) {
                    app.showError('Select paired device to connect');
                    app.goTo('paired-devices');
                    return;
                }

                app.connect(address);
            }
        );
    },

    connect: function (address) {
        $('#selected-device .status').text('Connecting...');

        // Attempt to connect device with specified address, call app.deviceConnected if success
        bluetoothSerial.connect(address, app.deviceConnected, function (error) {
            $('#selected-device .status').text('Disconnected');
            app.showError(error);
        });
    },

    deviceConnected: function () {
        // Subscribe to data receiving as soon as the delimiter is read
        bluetoothSerial.subscribe('\n', app.handleData, app.showError);

        $('#selected-device .status').text('Connected');
        $('#toggle-connection').text('Disconnect');
    },

    deviceDisconnected: function () {
        // Unsubscribe from data receiving
        bluetoothSerial.unsubscribe(app.handleData, app.showError);

        $('#selected-device .status').text('Disconnected');
        $('#toggle-connection').text('Connect');
    },

    handleData: function (data) {
        app.displayInTerminal(data, true);
        
    },

    sendData: function (event) {
        event.preventDefault();
        $('#C').on('vmousedown', function(){

            var chord = 2000;
            
            chord += '\n';
            app.displayInTerminal(chord, false);

            $('#F').attr("disabled", "disabled");
            $('#G').attr("disabled", "disabled");
            $('#D').attr("disabled", "disabled");
            $('#A').attr("disabled", "disabled");

            bluetoothSerial.write(chord, null, app.showError);

            });
        $('#C').on('vmouseup', function(){
                var chord = 2001;
            
                chord += '\n';
                app.displayInTerminal(chord, false);
        
                bluetoothSerial.write(chord, null, app.showError);
                $('#F').removeAttr("disabled");
                $('#G').removeAttr("disabled");
                $('#D').removeAttr("disabled");
                $('#A').removeAttr("disabled");
    
            });
        $('#F').on('vmousedown', function(){

            var Fchord = 3000;
            
            Fchord += '\n';
            app.displayInTerminal(Fchord, false);
    
            bluetoothSerial.write(Fchord, null, app.showError);

            $('#C').attr("disabled", "disabled");
            $('#G').attr("disabled", "disabled");
            $('#D').attr("disabled", "disabled");
            $('#A').attr("disabled", "disabled");
            
    
            });
            $('#F').on('vmouseup', function(){

            
                    var Fchord = 3001;
                
                    Fchord += '\n';
                    app.displayInTerminal(Fchord, false);
            
                    bluetoothSerial.write(Fchord, null, app.showError);
                    $('#C').removeAttr("disabled");
                    $('#G').removeAttr("disabled");
                    $('#D').removeAttr("disabled");
                    $('#A').removeAttr("disabled");
              
        
                });
            $('#A').on('vmousedown', function(){

                var Achord = 6000;
                
                Achord += '\n';
                app.displayInTerminal(Achord, false);
        
                bluetoothSerial.write(Achord, null, app.showError);
    
                $('#C').attr("disabled", "disabled");
                $('#G').attr("disabled", "disabled");
                $('#D').attr("disabled", "disabled");
                $('#F').attr("disabled", "disabled");
        
                });
            $('#A').on('vmouseup', function(){
                    var Achord = 6001;
                
                    Achord += '\n';
                    app.displayInTerminal(Achord, false);
            
                    bluetoothSerial.write(Achord, null, app.showError);
                    $('#C').removeAttr("disabled");
                    $('#G').removeAttr("disabled");
                    $('#D').removeAttr("disabled");
                    $('#F').removeAttr("disabled");
                
        
                });
        $('#G').on('vmousedown', function(){

            var Gchord = 4000;
            
            Gchord += '\n';
            app.displayInTerminal(Gchord, false);
    
            bluetoothSerial.write(Gchord, null, app.showError);
            $('#C').attr("disabled", "disabled");
            $('#F').attr("disabled", "disabled");
            $('#D').attr("disabled", "disabled");
            $('#A').attr("disabled", "disabled");
    
        });
        $('#G').on('vmouseup', function(){
                var Gchord = 4001; 
                Gchord += '\n';
                app.displayInTerminal(Gchord, false);
        
                bluetoothSerial.write(Gchord, null, app.showError);
                $('#C').removeAttr("disabled");
                $('#F').removeAttr("disabled");
                $('#D').removeAttr("disabled");
                $('#A').removeAttr("disabled");
          
        });
        $('#D').on('vmousedown', function(){

            var Dchord = 5000;
            
            Dchord += '\n';
            app.displayInTerminal(Dchord, false);
    
            bluetoothSerial.write(Dchord, null, app.showError);
            $('#C').attr("disabled", "disabled");
            $('#F').attr("disabled", "disabled");
            $('#G').attr("disabled", "disabled");
            $('#A').attr("disabled", "disabled");
           
    
        });
        $('#D').on('vmouseup', function(){

           
                var Dchord = 5001;
            
                Dchord += '\n';
                app.displayInTerminal(Dchord, false);
        
                bluetoothSerial.write(Dchord, null, app.showError);
                $('#C').removeAttr("disabled");
                $('#F').removeAttr("disabled");
                $('#G').removeAttr("disabled");
                $('#A').removeAttr("disabled");
           
    
        });
        $('#start_strumming').click(function(){
            $('#stop_strumming').show();
            $('#start_strumming').hide();
            var start = 9000;
            
            start += '\n';
            app.displayInTerminal(start, false);
    
            bluetoothSerial.write(start, null, app.showError);
    
        });
        $('#stop_strumming').click(function(){
            $('#stop_strumming').hide();
            $('#start_strumming').show();
            var start = 9001;
            
            start += '\n';
            app.displayInTerminal(start, false);
    
            bluetoothSerial.write(start, null, app.showError);
    
        });
        
        setInterval(function(){
            var data = X;
            data += '\n';
            app.displayInTerminal(data, false);

            bluetoothSerial.write(data, null, app.showError);
        },100);
    },

    displayInTerminal: function (data, isIncoming) {
        var $dataContainer = $('#data');

        if (isIncoming) {
            data = '<span class="in">' + data + '</span>';
        }
        else {
            data = '<span class="out">' + data + '</span>';
        }

        $dataContainer.append(data);

        if ($('#terminal input[name=autoscroll]').is(':checked')) {
            $dataContainer.scrollTop($dataContainer[0].scrollHeight - $dataContainer.height());
        }
    },

    clearData: function () {
        $('#data').text('');
    },

    goTo: function (state) {
        $('.state').hide();
        $('#' + state + '.state').show();
    },

    showError: function (error) {
        alert(error);
    },
    receivedEvent: function(id) {
        var parentElement = document.getElementById(id);
        var listeningElement = parentElement.querySelector('.listening');
        var receivedElement = parentElement.querySelector('.received');
    
        listeningElement.setAttribute('style', 'display:none;');
        receivedElement.setAttribute('style', 'display:block;');
    
        console.log('Received Event: ' + id);
       
      },
    
      startWatch: function() {
        
        var options = { frequency: 100 };
        
        watchID = navigator.accelerometer.watchAcceleration(app.accelerometerSucces, app.accelerometerError, options);
        
      },
    
      accelerometerSucces: function(acceleration) {
        var element = document.getElementById('accelerometerDiv');
        
    
        accelerationX = acceleration.x;
        accelerationY = acceleration.y;
        accelerationZ = acceleration.z;
        var accX = accelerationX.toFixed(0);
        X = accelerationX.toFixed(0);
        
        document.getElementById("x").innerHTML = accelerationX.toFixed(0);
        document.getElementById("y").innerHTML = X;
        document.getElementById("z").innerHTML = accX;

        bluetoothSerial.connect(address, app.deviceConnected, function (error) {
            $('#selected-device .status').text('Disconnected');
            app.showError(error);
        });
    
      },
    
      accelerometerError: function() {
        alert('onError!');
      },

};


app.initialize();
