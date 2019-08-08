<template>
    <h2 >11{{msg}}111333366666666666612222</h2>
</template>
<script>
export default {
    data(){
        return{
        
        }
    },
    props:['msg'],
    created(){
        this.$emit('myEvent',345)
    }
}
</script>

