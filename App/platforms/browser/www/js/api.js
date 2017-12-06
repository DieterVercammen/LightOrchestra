$(function() {
    
    $("#button1").click(function(){
        $.ajax({url: "http://192.168.1.102/arduino/digital/9/1", success: function(result){
            $("#div1").html(result);
        }});
    });
    $("#button2").click(function(){
        $.ajax({url: "http://192.168.1.102/arduino/digital/9/0", success: function(result){
            $("#div1").html(result);
        }});
    });

});