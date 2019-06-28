$(document).ready(function () {
    var fontSize = $('#fire').css('font-size');
    refresh();
    function refresh() {
        $.ajax({
            type: 'get',
            url: '/getData.php',
            dataType: 'json',
            success: function (data) {
                $('#temp').html(data['temp']);
                $('#humid').html(data['humid']);
                if (data['fire'] != 0) {
                    $('#fire').html('Detected');
                    $('#fire').css('font-size', '50px')
                } else {
                    $('#fire').html('OK');
                    $('#fire').css('font-size', fontSize)
                }

                if (data['more'] != 0) {
                    $('#more').html('Detected');
                    $('#more').css('font-size', '50px')
                } else {
                    $('#more').html('OK');
                    $('#more').css('font-size', fontSize)
                }

                $('#name').html(data['nodeName']);
                refresh();
            },
            error: function (e) {
                $('#name').html(e);
                refresh();
            }
        });
    }
});