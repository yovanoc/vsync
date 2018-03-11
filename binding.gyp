{
  "targets": [
    {
      "target_name": "zsync",
      "sources": [ "zsync.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}