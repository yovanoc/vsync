{
  "targets": [
    {
      "target_name": "vsync",
      "sources": [ "vsync.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}